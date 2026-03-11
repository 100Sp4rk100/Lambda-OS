#ifndef TOWN_ANIMATION_H
#define TOWN_ANIMATION_H

#include "../animation_template.h"
#include <kandinsky/context.h>

namespace Theme {

class TownAnimation {
    public:
        AnimationTemplate getTemplate(int i);
        void update();
        void setup();
        int getNumberOfImages() const;

    private:
        static constexpr int kpixels = 15;
        static constexpr int x[kpixels] = {2, 49, 71, 95, 128, 133, 168, 190, 195, 209, 285, 309, 316, 300, 304};
        static constexpr int y[kpixels] = {68, 117, 117, 28, 28, 32, 103, 103, 106, 56, 117, 117, 120, 89, 91};
        static constexpr int delay[kpixels] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        static constexpr uint16_t colors[kpixels] = {0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800};
        int count[kpixels];
};

}

#endif