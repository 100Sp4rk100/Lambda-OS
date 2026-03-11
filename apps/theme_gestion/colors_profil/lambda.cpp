#include "lambda.h"

namespace Theme {

KDColor LambdaColorProfil::getColor(const char* name) const{

    if (strcmp(name, "YellowDark") == 0) {
        return Escher::Palette::LAMDA_green_palette;
    }
    else if (strcmp(name, "YellowLight") == 0) {
        return Escher::Palette::LAMDA_green_light_palette;
    }
    else if (strcmp(name, "PurpleBright") == 0) {
        return Escher::Palette::PurpleBright;
    }
    else if (strcmp(name, "PurpleDark") == 0) {
        return Escher::Palette::PurpleDark;
    }
    else if (strcmp(name, "GrayWhite") == 0) {
        return Escher::Palette::LAMDA_gray_palette;
    }
    else if (strcmp(name, "GrayBright") == 0) {
        return Escher::Palette::GrayBright;
    }
    else if (strcmp(name, "GrayMiddle") == 0) {
        return Escher::Palette::GrayMiddle;
    }
    else if (strcmp(name, "GrayDarkMiddle") == 0) {
        return Escher::Palette::GrayDarkMiddle;
    }
    else if (strcmp(name, "GrayDark") == 0) {
        return Escher::Palette::GrayDark;
    }
    else if (strcmp(name, "GrayVeryDark") == 0) {
        return Escher::Palette::LAMDA_green_palette;
    }
    else if (strcmp(name, "GrayDarkest") == 0) {
        return Escher::Palette::GrayDarkest;
    }
    else if (strcmp(name, "Select") == 0) {
        return Escher::Palette::LAMDA_gray_light_palette;
    }
    else if (strcmp(name, "SelectDark") == 0) {
        return Escher::Palette::SelectDark;
    }
    else if (strcmp(name, "WallScreen") == 0) {
        return Escher::Palette::LAMDA_gray_palette;
    }
    else if (strcmp(name, "WallScreenDark") == 0) {
        return Escher::Palette::LAMDA_gray_light_palette;
    }
    else if (strcmp(name, "PopUpTitleBackground") == 0) {
        return Escher::Palette::LAMDA_green_palette;
    }
    else if (strcmp(name, "LowBattery") == 0) {
        return Escher::Palette::LowBattery;
    }
    else if (strcmp(name, "Red") == 0) {
        return Escher::Palette::Red;
    }
    else if (strcmp(name, "RedLight") == 0) {
        return Escher::Palette::RedLight;
    }
    else if (strcmp(name, "Magenta") == 0) {
        return Escher::Palette::Magenta;
    }
    else if (strcmp(name, "Turquoise") == 0) {
        return Escher::Palette::Turquoise;
    }
    else if (strcmp(name, "Pink") == 0) {
        return Escher::Palette::Pink;
    }
    else if (strcmp(name, "Blue") == 0) {
        return Escher::Palette::Blue;
    }
    else if (strcmp(name, "BlueLight") == 0) {
        return Escher::Palette::BlueLight;
    }
    else if (strcmp(name, "Orange") == 0) {
        return Escher::Palette::Orange;
    }
    else if (strcmp(name, "Green") == 0) {
        return Escher::Palette::Green;
    }
    else if (strcmp(name, "GreenLight") == 0) {
        return Escher::Palette::GreenLight;
    }
    else if (strcmp(name, "Brown") == 0) {
        return Escher::Palette::Brown;
    }
    else if (strcmp(name, "Purple") == 0) {
        return Escher::Palette::Purple;
    }
    else if (strcmp(name, "BlueishGray") == 0) {
        return Escher::Palette::BlueishGray;
    }
    else if (strcmp(name, "Cyan") == 0) {
        return Escher::Palette::Cyan;
    }else if (strcmp(name, "KDColorBlack") == 0) {
        return LAMDA_green;
    }else if (strcmp(name, "KDColorWhite") == 0) {
        return LAMDA_gray;
    }else if (strcmp(name, "KDColorRed") == 0) {
        return KDColorRed;
    }else if (strcmp(name, "KDColorGreen") == 0) {
        return KDColorGreen;
    }else if (strcmp(name, "KDColorBlue") == 0) {
        return KDColorBlue;
    }else if (strcmp(name, "KDColorYellow") == 0) {
        return KDColorYellow;
    }else if (strcmp(name, "KDColorOrange") == 0) {
        return KDColorOrange;
    }else if (strcmp(name, "KDColorPurple") == 0) {
        return KDColorPurple;
    }else if (strcmp(name, "TextHillightColor") == 0) {
        return KDColorBlue;
    }else if (strcmp(name, "TextColor") == 0) {
        return LAMDA_green;
    }else if (strcmp(name, "BackgroundColor") == 0) {
        return KDColorWhite;
    }else if (strcmp(name, "BackgroundColorHilight") == 0) {
        return Escher::Palette::YellowDark;
    }

    return KDColor::RGB888(255, 255, 255);
}

}
