#ifndef EPSILON_THEME_H
#define EPSILON_THEME_H

#include "apps/theme_gestion/theme.h"

namespace Theme {

class EpsilonTheme : public ThemeTemplate{
    public:
        const uint16_t* getBackground() const override;
        ColorProfil* getColorProfil() const override;
        bool isThereBackground() const override;
        bool isSquareIcon() const override;
        IconProfil* getIconProfil() const override;
        bool isAnimated() const override;
        AnimationTemplate getTemplate(int i) const override;
        int getNumberOfImages() const override;
        void setup() const override;
        void update() const override;
        bool isDynamicImages() const override;
    };

}

#endif