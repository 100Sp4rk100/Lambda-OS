#include <assert.h>
#include <escher/transparent_pointer_text_view.h>

namespace Escher {

TransparentPointerTextView::TransparentPointerTextView(const char* text, KDGlyph::Format format)
    : TransparentTextView(format), m_text(text) {}

void TransparentPointerTextView::setText(const char* text) {
  if (text != m_text) {
    m_text = text;
    markWholeFrameAsDirty();
  }
}

}  // namespace Escher
