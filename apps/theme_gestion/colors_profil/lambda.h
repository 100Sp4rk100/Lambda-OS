#ifndef LAMBDA_COLOR_PROFIL_H
#define LAMBDA_COLOR_PROFIL_H

#include "apps/theme_gestion/color_profil.h"

namespace Theme {

class LambdaColorProfil : public ColorProfil{
    public:
        KDColor getColor(const char* name) const override;
    };

}

#endif