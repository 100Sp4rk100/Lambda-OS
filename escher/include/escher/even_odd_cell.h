#ifndef ESCHER_EVEN_ODD_CELL_H
#define ESCHER_EVEN_ODD_CELL_H

#include <escher/highlight_cell.h>
#include <escher/metric.h>

#include "apps/theme_gestion/themeGestion.h"

namespace Escher {

class EvenOddCell : public HighlightCell {
 public:
  EvenOddCell();
  virtual void setEven(bool even);
  void setVisible(bool visible) override;
  void setHighlighted(bool highlighted) override;
  virtual KDColor backgroundColor() const;
  void drawRect(KDContext* ctx, KDRect rect) const override;

  constexpr static KDCoordinate k_horizontalMargin = Metric::SmallCellMargin;
  static KDGlyph::Format k_smallCellDefaultFormat();

 protected:
  virtual void updateSubviewsBackgroundAfterChangingState() {}
  bool m_even;
};

}  // namespace Escher

#endif
