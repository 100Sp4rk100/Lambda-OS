#include <escher/even_odd_cell.h>
#include <escher/palette.h>

#include "apps/theme_gestion/themeGestion.h"

namespace Escher {

KDGlyph::Format EvenOddCell::k_smallCellDefaultFormat(){
  return{
      .style = {.font = KDFont::Size::Small},
      .horizontalAlignment = KDGlyph::k_alignRight};
  }


EvenOddCell::EvenOddCell() : HighlightCell(), m_even(false) {}

void EvenOddCell::setEven(bool even) {
  if (even != m_even) {
    m_even = even;
    reloadCell();
  }
  updateSubviewsBackgroundAfterChangingState();
}

void EvenOddCell::setVisible(bool visible) {
  if (visible != isVisible()) {
    HighlightCell::setVisible(visible);
    updateSubviewsBackgroundAfterChangingState();
    reloadCell();
  }
}

void EvenOddCell::setHighlighted(bool highlighted) {
  HighlightCell::setHighlighted(highlighted);
  updateSubviewsBackgroundAfterChangingState();
}

KDColor EvenOddCell::backgroundColor() const {
  if (!isVisible()) {
    return Theme::ThemeGestion::getColor("WallScreenDark");
  } else if (isHighlighted()) {
    return Theme::ThemeGestion::getColor("Select");
  }
  return m_even ? Theme::ThemeGestion::getColor("KDColorWhite") : Theme::ThemeGestion::getColor("WallScreen");
}

void EvenOddCell::drawRect(KDContext* ctx, KDRect rect) const {
  KDColor background = backgroundColor();
  ctx->fillRect(rect, background);
}

}  // namespace Escher
