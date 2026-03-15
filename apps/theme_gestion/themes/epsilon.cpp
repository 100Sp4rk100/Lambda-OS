#include "epsilon.h"

#include "apps/theme_gestion/colors_profil/epsilon.h"
#include "apps/theme_gestion/icons_profil/epsilon.h"

namespace Theme {

static EpsilonColorProfil epsilonColorProfil;
static EpsilonIconProfil epsilonIconProfil;

const uint16_t* EpsilonTheme::getBackground() const {
    return Background::BackgroundGestion::getBackgroundNumber(0);
}

ColorProfil* EpsilonTheme::getColorProfil() const {
    return &epsilonColorProfil;
}

bool EpsilonTheme::isThereBackground() const{
    return false;
}

bool EpsilonTheme::isSquareIcon() const{
    return true;
}

IconProfil* EpsilonTheme::getIconProfil() const {
    return &epsilonIconProfil;
}

bool EpsilonTheme::isAnimated() const{
    return false;
}

AnimationTemplate EpsilonTheme::getTemplate(int i) const{
    return {0, 0, 0, 0, 0};
}

int EpsilonTheme::getNumberOfImages() const{
    return 0;
}

void EpsilonTheme::setup() const{}

void EpsilonTheme::update() const{}

bool EpsilonTheme::isDynamicImages() const{
    return false;
}

}
