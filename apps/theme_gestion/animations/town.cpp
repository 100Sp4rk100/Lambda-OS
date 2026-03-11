#include "town.h"

namespace Theme {

int TownAnimation::getNumberOfImages() const {
    return kpixels;
}

AnimationTemplate TownAnimation::getTemplate(int i) {
    return {x[i], y[i], delay[i], count[i], colors[i]};
}

void TownAnimation::update() {
    for (int i = 0; i < getNumberOfImages(); i++){
        if (count[i] == delay[i]*2) count[i] = 0;
        count[i]++;
    }
}

void TownAnimation::setup() {
    for (int i = 0; i < getNumberOfImages(); i++){
        count[i] = 0;
    }
}

}