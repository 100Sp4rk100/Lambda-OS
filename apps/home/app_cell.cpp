#include "app_cell.h"

#include <assert.h>

#include <escher/text_view.h>

#include <kandinsky/ion_context.h>

#include "apps/theme_gestion/themeGestion.h"
#include "apps/theme_gestion/backgroundGestion.h"

using namespace Escher;

namespace Home {

KDGlyph::Format AppCell::k_glyphsFormat(){
  return {
      .style = {.font = KDFont::Size::Small},
      .horizontalAlignment = KDGlyph::k_alignCenter};}

AppCell::AppCell()
    : HighlightCell(),
      m_messageNameView((I18n::Message)0, k_glyphsFormat()),
      m_image(0, 0, nullptr, 0),
      m_pointerNameView(nullptr, k_glyphsFormat()) {}

void AppCell::drawRect(KDContext *ctx, KDRect rect) const {
  KDSize nameSize = textView()->minimalSizeForOptimalDisplay();

  if (Theme::ThemeGestion::isThereBackground()){
    int width  = bounds().width();
    int height = nameSize.height() + 2 * k_nameHeightMargin;
    int yStart = bounds().height() - height;

    // Origine absolue de la cellule dans l’écran
    KDPoint absOrigin = absoluteOrigin();

    KDColor buffer[width * height];

    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        int srcX = absOrigin.x() + x;
        int srcY = absOrigin.y() + yStart + y - nameSize.height()-4;

        int srcIndex = srcY * background_width + srcX;
        int dstIndex = y * width + x;

        buffer[dstIndex] = reinterpret_cast<const KDColor *>(Theme::ThemeGestion::getBackground())[srcIndex];
      }
    }

    ctx->fillRectWithPixels(
      KDRect(0, yStart, width, height),
      buffer,
      nullptr
    );
  }else {
    KDSize nameSize = textView()->minimalSizeForOptimalDisplay();
    ctx->fillRect(
        KDRect(0, bounds().height() - nameSize.height() - 2 * k_nameHeightMargin,
              bounds().width(), nameSize.height() + 2 * k_nameHeightMargin),
        Theme::ThemeGestion::getBackgroundColor());
  }
}

int AppCell::numberOfSubviews() const { return isVisible() ? 2 : 0; }

View *AppCell::subviewAtIndex(int index) {
  View *views[] = {&m_iconView, const_cast<TransparentTextView *>(textView())};
  return views[index];
}

void AppCell::layoutSubviews(bool force) {
  setChildFrame(&m_iconView,
                KDRect((bounds().width() - k_iconWidth) / 2, k_iconMargin,
                       k_iconWidth, k_iconHeight),
                force);
  KDSize nameSize = textView()->minimalSizeForOptimalDisplay();
  setChildFrame(
      const_cast<TransparentTextView *>(textView()),
      KDRect((bounds().width() - nameSize.width()) / 2 - k_nameWidthMargin,
             bounds().height() - nameSize.height() - 2 * k_nameHeightMargin,
             nameSize.width() + 2 * k_nameWidthMargin,
             nameSize.height() + 2 * k_nameHeightMargin),
      force);
}

void AppCell::setBuiltinAppDescriptor(const ::App::Descriptor *descriptor) {
  m_iconView.setImage(descriptor->icon());
  m_messageNameView.setMessage(descriptor->name());
  m_pointerNameView.setText(nullptr);
  layoutSubviews();
  reloadCell();
}

void AppCell::setExternalApp(Ion::ExternalApps::App app) {
  m_pointerNameView.setText(app.name());
  m_messageNameView.setMessage((I18n::Message)0);
  m_image = Image(k_iconWidth, k_iconHeight, app.iconData(), app.iconSize());
  m_iconView.setImage(&m_image);
  layoutSubviews();
  reloadCell();
}

void AppCell::setVisible(bool visible) {
  if (isVisible() != visible) {
    Escher::HighlightCell::setVisible(visible);
    markWholeFrameAsDirty();
  }
}

void AppCell::reloadCell() {
  TransparentTextView *t = const_cast<TransparentTextView *>(textView());
  if (Theme::ThemeGestion::isThereBackground()){
    t->setTextColor(isHighlighted() ? Theme::ThemeGestion::getColor("TextHillightColor") : Theme::ThemeGestion::getColor("TextColor"));
  }else{
    t->setTextColor(isHighlighted() ? Theme::ThemeGestion::getColor("TextHillightColor") : Theme::ThemeGestion::getColor("TextColor"));
    t->setBackgroundColor(isHighlighted() ? Theme::ThemeGestion::getColor("BackgroundColorHilight") : Theme::ThemeGestion::getColor("BackgroundColor"));
  }
}

const Escher::TransparentTextView *AppCell::textView() const {
  if (m_pointerNameView.text()) {
    return &m_pointerNameView;
  } else {
    return &m_messageNameView;
  }
}

}  // namespace Home
