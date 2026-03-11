#ifndef THEME_H
#define THEME_H

#include "color_profil.h"
#include "icon_profil.h"
#include "animation_template.h"

namespace Theme {
class ThemeTemplate{
    public:
        virtual int getNumberBackground() const = 0;
        virtual ColorProfil* getColorProfil() const = 0;
        virtual bool isThereBackground() const = 0;
        virtual bool isSquareIcon() const = 0;
        virtual IconProfil* getIconProfil() const = 0;
        virtual bool isAnimated() const = 0;
        virtual AnimationTemplate getTemplate(int i) const = 0;
        virtual int getNumberOfImages() const = 0;
        virtual void update() const = 0;
        virtual void setup() const = 0;
        virtual bool isDynamicImages() const = 0;
};
}

#endif