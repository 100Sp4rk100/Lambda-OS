#ifndef TRANSPARENT_POINTER_TEXT_VIEW_H
#define TRANSPARENT_POINTER_TEXT_VIEW_H

#include <escher/i18n.h>
#include "transparent_text_view.h"

namespace Escher {

class TransparentPointerTextView : public TransparentTextView {
 public:
  TransparentPointerTextView(const char* text = nullptr, KDGlyph::Format format = {});
  const char* text() const override { return m_text; }
  void setText(const char* text) override;

 private:
  const char* m_text;
};

}  // namespace Escher
#endif
