#ifndef APPS_CLOCK_TIMER_H
#define APPS_CLOCK_TIMER_H

#include <escher/timer.h>

namespace ClockTimer{

  class ClockTimer : public Escher::Timer {
  public:

    static ClockTimer& instance();

    static void init();
    static void set(int h, int m, int s);
    static const char * get();
    static const char * getAll();

    static int8_t second;
    static int8_t minute;
    static int8_t hour;

    static bool isEnabled();

    static void activate();
    static void desactivate();

  private:

    static ClockTimer s_instance;

    static bool enable;

    ClockTimer();

    bool fire() override;

    static int accumulatedMs;
  };

}

#endif
