#ifndef DYNAMIC_COLOR_PROFIL_H
#define DYNAMIC_COLOR_PROFIL_H

#include "apps/theme_gestion/color_profil.h"

namespace Theme {

class DynamicColorProfil : public ColorProfil{
    public:
        KDColor getColor(const char* name) const override;
    };
}

#endif