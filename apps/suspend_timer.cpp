#include "suspend_timer.h"

#include "apps_container.h"

#include "clock_timer.h"

SuspendTimer::SuspendTimer()
    : Timer(k_idleBeforeSuspendDuration / Timer::TickDuration) {}

bool SuspendTimer::fire() {

  AppsContainer* container = AppsContainer::sharedAppsContainer();
  if (ClockTimer::ClockTimer::isEnabled()){
    container->switchToBuiltinApp(container->offAppSnapshot());
  }else{
    Ion::Power::suspend();
  }
  
  return false;
}
