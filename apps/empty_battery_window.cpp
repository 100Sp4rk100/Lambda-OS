#include "empty_battery_window.h"

#include <apps/i18n.h>
#include <ion.h>
extern "C" {
#include <assert.h>
}

#include "apps/theme_gestion/themeGestion.h"

EmptyBatteryWindow::EmptyBatteryWindow() : Window() {}

void EmptyBatteryWindow::drawRect(KDContext* ctx, KDRect rect) const {
  ctx->fillRect(bounds(), Theme::ThemeGestion::getColor("KDColorWhite"));
  const char* warningMessage = I18n::translate(I18n::Message::LowBattery);
  ctx->alignAndDrawString(warningMessage, KDPointZero,
                          KDSize(Ion::Display::Width, Ion::Display::Height),
                          {.horizontalAlignment = KDGlyph::k_alignCenter});
}
