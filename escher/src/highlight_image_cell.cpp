#include <escher/highlight_image_cell.h>

#include "apps/theme_gestion/themeGestion.h"

namespace Escher {

HighlightImageCell::HighlightImageCell() : HighlightCell() {
  m_contentView.setBackgroundColor(Theme::ThemeGestion::getColor("KDColorWhite"));
}

void HighlightImageCell::setHighlighted(bool highlighted) {
  m_contentView.setBackgroundColor(highlighted ? Theme::ThemeGestion::getColor("Select")
                                               : Theme::ThemeGestion::getColor("KDColorWhite"));
  HighlightCell::setHighlighted(highlighted);
}

KDSize HighlightImageCell::minimalSizeForOptimalDisplay() const {
  return m_contentView.minimalSizeForOptimalDisplay();
}

void HighlightImageCell::layoutSubviews(bool force) {
  setChildFrame(&m_contentView, bounds(), force);
}

}  // namespace Escher
