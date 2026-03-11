#include "lambda_2.h"

#include "apps/theme_gestion/colors_profil/lambda.h"
#include "apps/theme_gestion/icons_profil/lambda.h"

namespace Theme {

static LambdaColorProfil lambdaColorProfil;
static LambdaIconProfil lambdaIconProfil;

int Lambda2Theme::getNumberBackground() const {
    return 1;
}

ColorProfil* Lambda2Theme::getColorProfil() const {
    return &lambdaColorProfil;
}

bool Lambda2Theme::isThereBackground() const{
    return true;
}

bool Lambda2Theme::isSquareIcon() const{
    return false;
}

IconProfil* Lambda2Theme::getIconProfil() const {
    return &lambdaIconProfil;
}

bool Lambda2Theme::isAnimated() const{
    return false;
}

AnimationTemplate Lambda2Theme::getTemplate(int i) const{
    return {0, 0, 0, 0, 0};
}

int Lambda2Theme::getNumberOfImages() const{
    return 0;
}

void Lambda2Theme::setup() const{}

void Lambda2Theme::update() const{}

bool Lambda2Theme::isDynamicImages() const{
    return false;
}

}
