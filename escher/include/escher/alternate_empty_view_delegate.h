#ifndef ESCHER_ALTERNATE_EMPTY_VIEW_DELEGATE_H
#define ESCHER_ALTERNATE_EMPTY_VIEW_DELEGATE_H

#include <escher/i18n.h>
#include <escher/message_text_view.h>
#include <escher/palette.h>
#include <escher/view_controller.h>

#include "apps/theme_gestion/themeGestion.h"

namespace Escher {

class AlternateEmptyViewDelegate {
 public:
  AlternateEmptyViewDelegate()
      : m_emptyView((I18n::Message)0,
                    {.style = {.backgroundColor = Theme::ThemeGestion::getColor("WallScreen"),
                               .font = KDFont::Size::Small},
                     .horizontalAlignment = KDGlyph::k_alignCenter}) {}
  virtual bool isEmpty() const = 0;
  View* emptyView() {
    m_emptyView.setMessage(emptyMessage());
    return &m_emptyView;
  }
  virtual I18n::Message emptyMessage() = 0;
  virtual Responder* responderWhenEmpty() = 0;

 private:
  MessageTextView m_emptyView;
};

}  // namespace Escher

#endif
