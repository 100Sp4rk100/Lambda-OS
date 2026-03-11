#ifndef EPSILON_COLOR_PROFIL_H
#define EPSILON_COLOR_PROFIL_H

#include "apps/theme_gestion/color_profil.h"

namespace Theme {

class EpsilonColorProfil : public ColorProfil{
    public:
        KDColor getColor(const char* name) const override;
    };

}

#endif