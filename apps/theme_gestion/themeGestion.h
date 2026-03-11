#ifndef THEMEGESTION_H
#define THEMEGESTION_H

#include <stdint.h>
#include <escher/image.h>
#include <kandinsky/color.h>

#include "theme.h"
#include "animation_template.h"

class KDContext;

namespace Theme {

class ThemeGestion{

    public:
        static void setCurrent(int n);
        static const uint16_t* getBackground();
        static bool isSquareIcon();
        static void changeSquareIconState();
        static void setSquareIconState(bool state);
        static KDColor getColor(const char* name);
        static bool isThereBackground();
        static KDColor getBackgroundColor();
        static const Escher::Image * getIconImage(const char* name);
        static void editImageWithDynamicColor(KDColor *buffer, int pixelBufferSize);
        static void drawTemplateForAnimations();
        static void setup();

    private:
        static int current;
        static bool squareIcon;

        static constexpr int NB_TEMPLATE = 5;
        static const ThemeTemplate* all_template[NB_TEMPLATE];
};

}

#endif