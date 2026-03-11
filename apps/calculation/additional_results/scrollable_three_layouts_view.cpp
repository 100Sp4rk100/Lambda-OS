#include "scrollable_three_layouts_view.h"

#include <poincare/exception_checkpoint.h>

#include "apps/theme_gestion/themeGestion.h"

#include "../app.h"

using namespace Escher;
using namespace Poincare;

namespace Calculation {

void ScrollableThreeLayoutsView::ContentCell::reloadTextColor() {
  KDColor color = displayCenter() && !rightIsStrictlyEqual()
                      ? Theme::ThemeGestion::getColor("GrayVeryDark")
                      : Theme::ThemeGestion::getColor("KDColorBlack");
  rightLayoutView()->setTextColor(color);
  approximateSign()->setTextColor(color);
}

void ScrollableThreeLayoutsView::setLayouts(Layout formulaLayout,
                                            Layout exactLayout,
                                            Layout approximateLayout) {
  AbstractScrollableMultipleLayoutsView::setLayouts(formulaLayout, exactLayout,
                                                    approximateLayout);
  setShowEqualSignAfterFormula(!exactLayout.isUninitialized() ||
                               !approximateLayout.isUninitialized());
}

ScrollableThreeLayoutsView::SubviewPosition
ScrollableThreeLayoutsView::leftMostPosition() {
  if (!m_contentCell.m_leftLayoutView.layout().isUninitialized()) {
    return SubviewPosition::Left;
  } else if (displayCenter()) {
    return SubviewPosition::Center;
  }
  return SubviewPosition::Right;
}

}  // namespace Calculation
