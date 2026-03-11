#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <kandinsky/color.h>

namespace Theme {

struct AnimationTemplate {
    int x;
    int y;
    int delay;
    int count;
    uint16_t color;
};

}

#endif