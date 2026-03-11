#ifndef TRANSPARENT_MESSAGE_TEXT_VIEW_H
#define TRANSPARENT_MESSAGE_TEXT_VIEW_H

#include <escher/i18n.h>
#include "transparent_text_view.h"

namespace Escher {

class TransparentMessageTextView : public TransparentTextView {
 public:
  using TitleType = I18n::Message;

  TransparentMessageTextView(I18n::Message message = (I18n::Message)0,
                  KDGlyph::Format format = {}, KDCoordinate lineSpacing = 0)
      : TransparentTextView(format, lineSpacing), m_message(message) {}

  void setText(const char* text) override;
  void setMessage(I18n::Message message);
  const char* text() const override;

 private:
  I18n::Message m_message;
};

}  // namespace Escher

#endif
