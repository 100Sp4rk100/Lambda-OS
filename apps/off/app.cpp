#include "app.h"

#include "apps/i18n.h"
#include "apps/apps_container.h"
#include "apps/theme_gestion/themeGestion.h"
#include <apps/global_preferences.h>

#include "../clock_timer.h"

namespace Off_screen {

I18n::Message App::Descriptor::name() const {
  return I18n::Message::OffApp;
}

I18n::Message App::Descriptor::upperName() const {
  return I18n::Message::OffAppCapital;
}

const Escher::Image* App::Descriptor::icon() const { 
  return Theme::ThemeGestion::getIconImage("OffIcon"); 
}

App * App::Snapshot::unpack(Escher::Container * container) {
  return new (container->currentAppBuffer()) App(this);
}

App::Descriptor * App::Snapshot::descriptor() const{
  static Descriptor descriptor;
  return &descriptor;
}

App::App(Snapshot * snapshot) :
  Escher::App(snapshot, &m_offController){
    AppsContainer* container = AppsContainer::sharedAppsContainer();
    GlobalPreferences* globalPreferences = GlobalPreferences::SharedGlobalPreferences();

    bright = globalPreferences->brightnessLevel();

    if (ClockTimer::ClockTimer::isEnabled()){
      globalPreferences->setBrightnessLevel(0);

      //container->hide_title_bar_win();

      Ion::Backlight::setBrightness(globalPreferences->brightnessLevel());

      Ion::Display::pushRectUniform(KDRect(0, -2, Ion::Display::Width, Ion::Display::Height+2),KDColorBlack);
    }else{
      Ion::Power::suspend();
      container->switchToBuiltinApp(container->homeAppSnapshot());
    }
  }

void App::willBecomeInactive() {
  GlobalPreferences* globalPreferences = GlobalPreferences::SharedGlobalPreferences();
  globalPreferences->setBrightnessLevel(bright);

  Ion::Backlight::setBrightness(globalPreferences->brightnessLevel());
  Escher::App::willBecomeInactive();
}

}