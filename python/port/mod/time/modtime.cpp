extern "C" {
#include "modtime.h"
}
#include <ion/timing.h>
#include <limits.h>
#include <py/runtime.h>
#include <py/smallint.h>

#include "../../helpers.h"

#include "apps/clock_timer.h"

mp_obj_t modtime_sleep(mp_obj_t seconds_o) {
#if MICROPY_PY_BUILTINS_FLOAT
  mp_float_t duration = mp_obj_get_float(seconds_o);
#else
  mp_int_t duration = mp_obj_get_int(seconds_o);
#endif
  int32_t duration32 =
      duration < 0 ? 0
                   : (duration > INT_MAX / 1000 ? INT_MAX : 1000 * duration);
  micropython_port_interruptible_msleep(duration32);
  return mp_const_none;
}

mp_obj_t modtime_monotonic() {
  return mp_obj_new_float(Ion::Timing::millis() / 1000.0);
}

mp_obj_t modtime_getTime() {
  return mp_obj_new_str(ClockTimer::ClockTimer::getAll(), 9);
}

mp_obj_t modtime_setTime(mp_obj_t h, mp_obj_t m, mp_obj_t s) {
  int h_int = mp_obj_get_int(h);
  int m_int = mp_obj_get_int(m);
  int s_int = mp_obj_get_int(s);
  if (h_int<24 && 0<=h_int && m_int<60 && 0<=m_int && s_int<60 && 0<=s_int){
    ClockTimer::ClockTimer::set(h_int, m_int, s_int);
  }
  return mp_const_none;
}

mp_obj_t modtime_resetTime() {
  ClockTimer::ClockTimer::init();
  return mp_const_none;
}