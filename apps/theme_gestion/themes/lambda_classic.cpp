#include "lambda_classic.h"

#include "apps/theme_gestion/colors_profil/lambda.h"
#include "apps/theme_gestion/icons_profil/lambda.h"

namespace Theme {

static LambdaColorProfil lambdaColorProfil;
static LambdaIconProfil lambdaIconProfil;

int LambdaClassicTheme::getNumberBackground() const {
    return 0;
}

ColorProfil* LambdaClassicTheme::getColorProfil() const {
    return &lambdaColorProfil;
}

bool LambdaClassicTheme::isThereBackground() const{
    return true;
}

bool LambdaClassicTheme::isSquareIcon() const{
    return false;
}

IconProfil* LambdaClassicTheme::getIconProfil() const {
    return &lambdaIconProfil;
}

bool LambdaClassicTheme::isAnimated() const{
    return false;
}

Theme::AnimationTemplate LambdaClassicTheme::getTemplate(int i) const{
    return {0, 0, 0, 0, 0};
}

int LambdaClassicTheme::getNumberOfImages() const{
    return 0;
}

void LambdaClassicTheme::setup() const{}

void LambdaClassicTheme::update() const{}

bool LambdaClassicTheme::isDynamicImages() const{
    return false;
}

}
