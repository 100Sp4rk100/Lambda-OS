#ifndef TOWN_COLOR_PROFIL_H
#define TOWN_COLOR_PROFIL_H

#include "apps/theme_gestion/color_profil.h"

namespace Theme {

class TownColorProfil : public ColorProfil{
    public:
        KDColor getColor(const char* name) const override;
    };

}

#endif