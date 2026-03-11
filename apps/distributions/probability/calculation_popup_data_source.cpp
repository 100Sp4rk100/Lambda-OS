#include "calculation_popup_data_source.h"

#include "apps/theme_gestion/themeGestion.h"

namespace Distributions {

CalculationPopupDataSource::CalculationPopupDataSource(
    Distribution* distribution)
    : m_distribution(distribution) {
  /* We can init the image of all cells because there is a bijection of the
   * displayable cells and the source cells. */
  const Escher::Image* images[k_numberOfImages] = {
      Theme::ThemeGestion::getIconImage("Calculation1Icon"), Theme::ThemeGestion::getIconImage("Calculation2Icon"),
      Theme::ThemeGestion::getIconImage("Calculation3Icon"), Theme::ThemeGestion::getIconImage("Calculation4Icon")};
  for (int i = 0; i < k_numberOfImages; i++) {
    m_imageCells[i].setImage(images[i]);
  }
}

int CalculationPopupDataSource::numberOfRows() const {
  if (!m_distribution->allParametersAreInitialized()) {
    // Only display left and right integral
    return 2;
  }
  return k_numberOfImages - m_distribution->isContinuous();
}

int CalculationPopupDataSource::absoluteRow(int currentRow) const {
  if (!m_distribution->allParametersAreInitialized() && currentRow == 1) {
    // Only display left and right integral
    return 2;
  }
  return currentRow;
}

}  // namespace Distributions
