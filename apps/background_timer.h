#ifndef BACKGROUND_TIMER_H
#define BACKGROUND_TIMER_H

#include <escher/timer.h>

namespace BackgroundTimer{

class BackgroundTimer : public Escher::Timer {
 public:
  static BackgroundTimer& instance();

 private:
  constexpr static int k_idleBeforeDimmingDuration = 300;  // In miliseconds
  bool fire() override;

  BackgroundTimer();
};

#endif

}