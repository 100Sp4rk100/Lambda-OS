#include "clock_timer.h"

#include <ion.h>
#include "apps_container.h"

namespace ClockTimer{

  int8_t ClockTimer::second = 0;
  int8_t ClockTimer::minute = 0;
  int8_t ClockTimer::hour = 0;
  bool ClockTimer::enable = true;
  int ClockTimer::accumulatedMs = 0;

  ClockTimer& ClockTimer::instance() {
    static ClockTimer inst;
    return inst;
  }

  ClockTimer::ClockTimer()
      : Timer(1) {}

  void ClockTimer::init(){
    second = 0;
    minute = 0;
    hour = 0;
    accumulatedMs = 0;
    AppsContainer::sharedAppsContainer()->updateTime(hour, minute);
  }

  void ClockTimer::set(int h, int m, int s){
    second = s;
    minute = m;
    hour = h;
    AppsContainer::sharedAppsContainer()->updateTime(hour, minute);
  }

  const char * ClockTimer::get(){
    static char buf[6];
    buf[0] = (hour / 10) + '0';
    buf[1] = (hour % 10) + '0';
    buf[2] = ':';
    buf[3] = (minute / 10) + '0';
    buf[4] = (minute % 10) + '0';
    buf[5]   = '\0';

    return buf;
  }

  const char * ClockTimer::getAll(){
    static char buf[9];
    buf[0] = (hour / 10) + '0';
    buf[1] = (hour % 10) + '0';
    buf[2] = ':';
    buf[3] = (minute / 10) + '0';
    buf[4] = (minute % 10) + '0';
    buf[5] = ':';
    buf[6] = (second / 10) + '0';
    buf[7] = (second % 10) + '0';
    buf[8]   = '\0';

    return buf;
  }

  bool ClockTimer::fire() {
    accumulatedMs += Timer::TickDuration;

    if (accumulatedMs >= 1000) {
      accumulatedMs -= 1000;
      second++;
      if (second >= 60) {
        second = 0;
        minute++;
        if (minute >= 60) {
          minute = 0;
          hour++;
          if (hour >= 24) {
            hour = 0;
          }
        }
        AppsContainer::sharedAppsContainer()->updateTime(hour, minute);
      }
    }

    return true;
  }

bool ClockTimer::isEnabled() {
  return enable;
}

void ClockTimer::activate() {
  enable = true;
  init();
}

void ClockTimer::desactivate() {
  enable = false;
  init();
}


}  // namespace ClockTimer