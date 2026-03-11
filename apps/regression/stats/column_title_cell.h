#ifndef REGRESSION_COLUMN_TITLE_CELL_H
#define REGRESSION_COLUMN_TITLE_CELL_H

#include "even_odd_double_buffer_text_cell.h"

#include "apps/theme_gestion/themeGestion.h"

namespace Regression {

class ColumnTitleCell : public EvenOddDoubleBufferTextCell {
 public:
  ColumnTitleCell(Escher::Responder* parentResponder = nullptr)
      : EvenOddDoubleBufferTextCell(
            parentResponder, {.style = {.font = KDFont::Size::Small},
                              .horizontalAlignment = KDGlyph::k_alignCenter}),
        m_functionColor(Theme::ThemeGestion::getColor("Red")) {}
  virtual void setColor(KDColor color);
  void drawRect(KDContext* ctx, KDRect rect) const override;
  void layoutSubviews(bool force = false) override;

 private:
  constexpr static KDCoordinate k_colorIndicatorThickness =
      Escher::Metric::HorizontalColorIndicatorThickness;
  KDColor m_functionColor;
};

}  // namespace Regression

#endif
