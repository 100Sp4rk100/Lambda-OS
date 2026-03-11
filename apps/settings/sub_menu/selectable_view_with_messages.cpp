#include "selectable_view_with_messages.h"

#include <apps/i18n.h>
#include <assert.h>

#include <algorithm>

#include "apps/theme_gestion/themeGestion.h"

using namespace Shared;
using namespace Escher;

namespace Settings {

SelectableViewWithMessages::SelectableViewWithMessages(
    SelectableTableView* selectableTableView)
    : m_selectableTableView(selectableTableView),
      m_messageTextView(I18n::Message::Default,
                        {.style = {.glyphColor = Theme::ThemeGestion::getColor("GrayDark"),
                                   .backgroundColor = Theme::ThemeGestion::getColor("WallScreen"),
                                   .font = KDFont::Size::Small},
                         .horizontalAlignment = KDGlyph::k_alignCenter,
                         .verticalAlignment = KDGlyph::k_alignCenter}) {}

void SelectableViewWithMessages::drawRect(KDContext* ctx, KDRect rect) const {
  ctx->fillRect(bounds(), Theme::ThemeGestion::getColor("WallScreen"));
}

void SelectableViewWithMessages::setMessage(I18n::Message message) {
  m_messageTextView.setMessage(message);
  layoutSubviews();
}

void SelectableViewWithMessages::reload() {
  m_selectableTableView->reloadData(false);
  layoutSubviews();
}

View* SelectableViewWithMessages::subviewAtIndex(int index) {
  assert(index >= 0 && index < numberOfSubviews());
  if (index == 0) {
    return m_selectableTableView;
  }
  assert(index == 1);
  return &m_messageTextView;
}

void SelectableViewWithMessages::layoutSubviews(bool force) {
  // Prioritize text position
  int emptyMessage = m_messageTextView.text()[0] == 0;
  KDCoordinate textHeight =
      emptyMessage ? 0
                   : m_messageTextView.minimalSizeForOptimalDisplay().height();
  KDCoordinate messageOrigin =
      bounds().height() - (emptyMessage ? 0 : Metric::CommonMargins.bottom()) -
      textHeight;

  // Layout the table view
  setChildFrame(m_selectableTableView,
                KDRect(0, 0, bounds().width(), messageOrigin), force);

  // Layout the text
  setChildFrame(&m_messageTextView,
                KDRect(0, messageOrigin, bounds().width(), textHeight), force);
}

}  // namespace Settings
