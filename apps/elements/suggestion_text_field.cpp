#include "suggestion_text_field.h"

#include "apps/theme_gestion/themeGestion.h"

using namespace Escher;

namespace Elements {

// SuggestionTextField::ContentView

SuggestionTextField::ContentView::ContentView()
    : AbstractTextField::ContentView(nullptr, MaxBufferSize(), {}),
      m_suggestion(nullptr) {}

void SuggestionTextField::ContentView::drawRect(KDContext* ctx,
                                                KDRect rect) const {
  AbstractTextField::ContentView::drawRect(ctx, rect);
  if (m_suggestion) {
    assert(strlen(m_suggestion) >= draftTextLength());
    ctx->drawString(suggestionSuffix(),
                    glyphFrameAtPosition(draftText(), draftTextEnd()).origin(),
                    {.glyphColor = Theme::ThemeGestion::getColor("GrayDark"),
                     .backgroundColor = Theme::ThemeGestion::getColor("KDColorWhite"),
                     .font = m_format.style.font});
  }
}

KDSize SuggestionTextField::ContentView::minimalSizeForOptimalDisplay() const {
  KDSize size = AbstractTextField::ContentView::minimalSizeForOptimalDisplay();
  return m_suggestion
             ? KDSize(size.width() + KDFont::Font(m_format.style.font)
                                         ->stringSize(suggestionSuffix())
                                         .width(),
                      size.height())
             : size;
}

void SuggestionTextField::ContentView::setSuggestion(const char* suggestion) {
  m_suggestion = suggestion;
  markWholeFrameAsDirty();
}

// SuggestionTextField

SuggestionTextField::SuggestionTextField(Responder* parentResponder,
                                         TextFieldDelegate* delegate)
    : AbstractTextField(parentResponder, &m_contentView, delegate) {
  setBackgroundColor(Theme::ThemeGestion::getColor("KDColorWhite"));
}

bool SuggestionTextField::handleEvent(Ion::Events::Event event) {
  if (cursorAtEndOfText() && m_contentView.suggestion() &&
      (event == Ion::Events::Left || event == Ion::Events::ShiftLeft ||
       event == Ion::Events::ShiftUp)) {
    // Dismiss suggestion on Left press
    m_contentView.setSuggestion(nullptr);
    return true;
  }
  bool result = AbstractTextField::handleEvent(event);
  // If a suggestion remains, cursor must be at the end of the text
  assert(!m_contentView.suggestion() || cursorAtEndOfText());
  return result;
}

void SuggestionTextField::commitSuggestion() {
  if (m_contentView.suggestion()) {
    setText(m_contentView.suggestion());
  }
}

}  // namespace Elements
