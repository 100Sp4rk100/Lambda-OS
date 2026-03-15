#include "town.h"

#include "apps/theme_gestion/colors_profil/town.h"
#include "apps/theme_gestion/icons_profil/epsilon.h"

#include "../animations/town.h"

namespace Theme {

static TownColorProfil townColorProfil;
static EpsilonIconProfil epsilonIconProfil;

static TownAnimation town_animattion;

const uint16_t* TownTheme::getBackground() const {
    return Background::BackgroundGestion::getBackgroundNumber(2);
}

ColorProfil* TownTheme::getColorProfil() const {
    return &townColorProfil;
}

bool TownTheme::isThereBackground() const{
    return true;
}

bool TownTheme::isSquareIcon() const{
    return true;
}

IconProfil* TownTheme::getIconProfil() const {
    return &epsilonIconProfil;
}

bool TownTheme::isAnimated() const{
    return true;
}

AnimationTemplate TownTheme::getTemplate(int i) const{
    return town_animattion.getTemplate(i);
}

int TownTheme::getNumberOfImages() const{
    return town_animattion.getNumberOfImages();
}

void TownTheme::setup() const{
    town_animattion.setup();
}

void TownTheme::update() const{
    town_animattion.update();
}

bool TownTheme::isDynamicImages() const{
    return true;
}

}
