#include <ion/led.h>
#include "apps/theme_gestion/themeGestion.h"

namespace Ion {
namespace LED {

KDColor getColor() { return Theme::ThemeGestion::getColor("KDColorBlack"); }

void setColor(KDColor c) {}

void setBlinking(uint16_t period, float dutyCycle) {}

void setLock(bool) {}

KDColor updateColorWithPlugAndCharge() { return Theme::ThemeGestion::getColor("KDColorBlack"); }

}  // namespace LED
}  // namespace Ion
