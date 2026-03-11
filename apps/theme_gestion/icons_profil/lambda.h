#ifndef LAMBDA_ICON_PROFIL_H
#define LAMBDA_ICON_PROFIL_H

#include "apps/theme_gestion/icon_profil.h"

namespace Theme {

class LambdaIconProfil : public IconProfil{
    public:
        const Escher::Image * getIcon(const char* name) const override;
    };
}

#endif