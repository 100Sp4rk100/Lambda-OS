#include "background_timer.h"

#include "apps_container.h"
#include "theme_gestion/themeGestion.h"

#include <ion.h>

namespace BackgroundTimer{

BackgroundTimer& BackgroundTimer::instance() {
    static BackgroundTimer inst;
    return inst;
}

BackgroundTimer::BackgroundTimer()
    : Timer(k_idleBeforeDimmingDuration / Timer::TickDuration) {}

bool BackgroundTimer::fire() {

    AppsContainer *container = AppsContainer::sharedAppsContainer();
    Escher::App::Snapshot *snapshot = container->activeApp()->snapshot();
  
    if(snapshot == container->homeAppSnapshot() || snapshot == container->lambdaAppSnapshot()){
        Theme::ThemeGestion::drawTemplateForAnimations();
    }

    return true;
}

}