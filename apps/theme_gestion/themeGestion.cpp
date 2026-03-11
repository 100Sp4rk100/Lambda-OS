#include "themeGestion.h"
#include "backgroundGestion.h"
#include "dynamicColorProfil_gestion.h"

#include "themes/epsilon.h"
#include "themes/town.h"
#include "themes/lambda_2.h"
#include "themes/lambda_classic.h"
#include "themes/dynamic.h"

#include <kandinsky/context.h>
#include <ion/display.h>

namespace Theme {

int ThemeGestion::current = 0;
bool ThemeGestion::squareIcon = false;

static EpsilonTheme epsilonTheme;
static TownTheme townTheme;
static Lambda2Theme lambda2Theme;
static LambdaClassicTheme lambdaClassicTheme;
static DynamicTheme dynamicTheme;

const ThemeTemplate* ThemeGestion::all_template[NB_TEMPLATE] = {
    &lambdaClassicTheme,
    &lambda2Theme,
    &townTheme,
    &epsilonTheme,
    &dynamicTheme
};

void ThemeGestion::setup(){
    all_template[current]->setup();
}

void ThemeGestion::setCurrent(int n) {
    if (n >= 0 && n < NB_TEMPLATE) {
        current = n;
        setSquareIconState(all_template[current]->isSquareIcon());
        all_template[current]->setup();
    }
}

void ThemeGestion::drawTemplateForAnimations(){
    if (!all_template[current]->isAnimated()) return;

    int number_images = all_template[current]->getNumberOfImages();

    for (int i = 0; i < number_images; i++){
        AnimationTemplate animTemplate  = all_template[current]->getTemplate(i);
        if (animTemplate.count == animTemplate.delay){
            int index = animTemplate.y * 320 + animTemplate.x;
            KDColor color = KDColor::RGB16(getBackground()[index]);
            Ion::Display::pushRect(KDRect(animTemplate.x, animTemplate.y, 1, 1), &color);
        }else if(animTemplate.count < animTemplate.delay){
            KDColor color = KDColor::RGB16(animTemplate.color);
            Ion::Display::pushRect(KDRect(animTemplate.x, animTemplate.y, 1, 1), &color);
        }
    }

    all_template[current]->update();
}

const uint16_t* ThemeGestion::getBackground() {
    return Background::BackgroundGestion::getBackgroundNumber(
        all_template[current]->getNumberBackground()
    );
}

bool ThemeGestion::isSquareIcon() {
    return squareIcon;
}

void ThemeGestion::setSquareIconState(bool state){
    squareIcon = state;
}

bool ThemeGestion::isThereBackground() {
    return all_template[current]->isThereBackground();
}

void ThemeGestion::changeSquareIconState() {
    squareIcon = !squareIcon;
}

KDColor ThemeGestion::getColor(const char* name) {
    return all_template[current]->getColorProfil()->getColor(name);
}

KDColor ThemeGestion::getBackgroundColor() {
    return all_template[current]->getColorProfil()->getColor("BackgroundColor");
}

const Escher::Image * ThemeGestion::getIconImage(const char* name) {
    return all_template[current]->getIconProfil()->getIcon(name);
}

void ThemeGestion::editImageWithDynamicColor(KDColor *buffer, int pixelBufferSize) {
    if (!all_template[current]->isDynamicImages()) return;
    
    KDColor newColor = getColor("YellowDark");
    KDColor target = KDColorYellow;

    for (int i = 0; i < pixelBufferSize; i++) {

        int dr = buffer[i].red() - target.red();
        int dg = buffer[i].green() - target.green();
        int db = buffer[i].blue() - target.blue();

        int distance = dr*dr + dg*dg + db*db;

        if (distance < 30000) {
            buffer[i] = newColor;
        }
    }
}

}