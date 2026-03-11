#include <py/obj.h>

mp_obj_t modtime_sleep(mp_obj_t seconds_o);
mp_obj_t modtime_monotonic();
mp_obj_t modtime_getTime();
mp_obj_t modtime_setTime(mp_obj_t h, mp_obj_t m, mp_obj_t s);
mp_obj_t modtime_resetTime();