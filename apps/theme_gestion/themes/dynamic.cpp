#include "dynamic.h"

#include "apps/theme_gestion/colors_profil/dynamic.h"
#include "apps/theme_gestion/icons_profil/epsilon.h"

#include "apps/theme_gestion/dynamicColorProfil_gestion.h"

namespace Theme {

static DynamicColorProfil dynamicColorProfil;
static EpsilonIconProfil epsilonIconProfil;

int DynamicTheme::getNumberBackground() const {
    return Theme::DynamicColorProfilGestion::background;
}

ColorProfil* DynamicTheme::getColorProfil() const {
    return &dynamicColorProfil;
}

bool DynamicTheme::isThereBackground() const{
    return Theme::DynamicColorProfilGestion::isBackground;
}

bool DynamicTheme::isSquareIcon() const{
    return Theme::DynamicColorProfilGestion::isSquareIcon;
}

IconProfil* DynamicTheme::getIconProfil() const {
    return Theme::DynamicColorProfilGestion::getIconProfil();
}

bool DynamicTheme::isAnimated() const{
    return false;
}

AnimationTemplate DynamicTheme::getTemplate(int i) const{
    return {0, 0, 0, 0, 0};
}

int DynamicTheme::getNumberOfImages() const{
    return 0;
}

void DynamicTheme::setup() const{}

void DynamicTheme::update() const{}

bool DynamicTheme::isDynamicImages() const{
    return Theme::DynamicColorProfilGestion::isDynamicImages;
}

}
