#include <assert.h>
#include <escher/transparent_message_text_view.h>


namespace Escher {

const char* TransparentMessageTextView::text() const { return I18n::translate(m_message); }

void TransparentMessageTextView::setText(const char* text) { assert(false); }

void TransparentMessageTextView::setMessage(I18n::Message message) {
  if (message != m_message) {
    m_message = message;
    markWholeFrameAsDirty();
  }
}

}  // namespace Escher
