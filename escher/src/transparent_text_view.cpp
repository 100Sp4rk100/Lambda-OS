#include <escher/transparent_text_view.h>

namespace Escher {

KDSize TransparentTextView::minimalSizeForOptimalDisplay() const {
  return KDFont::Font(m_glyphFormat.style.font)
      ->stringSize(text(), -1, m_lineSpacing);
}

void TransparentTextView::drawRect(KDContext* ctx, KDRect rect) const {
  if (text() == nullptr) {
    return;
  }

  ctx->drawTransparentStringAligned(text(), KDPointZero, bounds().size(), m_glyphFormat, -1, m_lineSpacing);
}

}  // namespace Escher
