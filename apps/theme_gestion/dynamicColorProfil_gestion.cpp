#include "dynamicColorProfil_gestion.h"
#include <kandinsky/color.h>
#include <ion/src/device/shared/drivers/userland_header.h>
#include "apps/theme_gestion/icons_profil/epsilon.h"
#include "apps/theme_gestion/icons_profil/lambda.h"

extern "C" {
  extern uint8_t _external_apps_flash_start;
}

namespace Theme {

KDColor DynamicColorProfilGestion::colors[DynamicColorProfilGestion::K_MAX_COLORS];
bool DynamicColorProfilGestion::isSquareIcon = true;
bool DynamicColorProfilGestion::isBackground = false;
int DynamicColorProfilGestion::background = 0;
int DynamicColorProfilGestion::iconProfil = 0;
bool DynamicColorProfilGestion::isDynamicImages = false;
bool DynamicColorProfilGestion::isImportBackground = false;

static EpsilonIconProfil epsilonIconProfil;
static LambdaIconProfil lambdaIconProfil;

bool DynamicColorProfilGestion::reload() {
    Ion::Storage::Record profil_record = Ion::Storage::FileSystem::sharedFileSystem->recordNamed("profil.theme");

    if (profil_record.isNull()) return false;
    
    Ion::Storage::Record::Data record_data = profil_record.value();
    const uint16_t * dataPtr = static_cast<const uint16_t *>(record_data.buffer);
    size_t totalUint16Count = record_data.size / sizeof(uint16_t);

    for (size_t i = 0; i < K_MAX_COLORS; i++) {
        colors[i] = KDColor::RGB16(dataPtr[i]);
    }

    isSquareIcon = (dataPtr[K_MAX_COLORS] == 0);
    isBackground = (dataPtr[K_MAX_COLORS+1] == 0);
    background = dataPtr[K_MAX_COLORS+2];
    iconProfil = dataPtr[K_MAX_COLORS+3];
    isDynamicImages = (dataPtr[K_MAX_COLORS+4] == 0);
    isImportBackground = (dataPtr[K_MAX_COLORS+5] == 0);

    return true;
};

const uint16_t* DynamicColorProfilGestion::getBackground() {
    return reinterpret_cast<const uint16_t*>(&_external_apps_flash_start);
}

IconProfil* DynamicColorProfilGestion::getIconProfil() {
    if (iconProfil==0) return &lambdaIconProfil;
    return &epsilonIconProfil;
};

KDColor DynamicColorProfilGestion::getColor(const char* name) {
    if (strcmp(name, "YellowDark") == 0) {
        return colors[0];
    }
    else if (strcmp(name, "YellowLight") == 0) {
        return colors[1];
    }
    else if (strcmp(name, "PurpleBright") == 0) {
        return colors[2];
    }
    else if (strcmp(name, "PurpleDark") == 0) {
        return colors[3];
    }
    else if (strcmp(name, "GrayWhite") == 0) {
        return colors[4];
    }
    else if (strcmp(name, "GrayBright") == 0) {
        return colors[5];
    }
    else if (strcmp(name, "GrayMiddle") == 0) {
        return colors[6];
    }
    else if (strcmp(name, "GrayDarkMiddle") == 0) {
        return colors[7];
    }
    else if (strcmp(name, "GrayDark") == 0) {
        return colors[8];
    }
    else if (strcmp(name, "GrayVeryDark") == 0) {
        return colors[9];
    }
    else if (strcmp(name, "GrayDarkest") == 0) {
        return colors[10];
    }
    else if (strcmp(name, "Select") == 0) {
        return colors[11];
    }
    else if (strcmp(name, "SelectDark") == 0) {
        return colors[12];
    }
    else if (strcmp(name, "WallScreen") == 0) {
        return colors[13];
    }
    else if (strcmp(name, "WallScreenDark") == 0) {
        return colors[14];
    }
    else if (strcmp(name, "PopUpTitleBackground") == 0) {
        return colors[15];
    }
    else if (strcmp(name, "LowBattery") == 0) {
        return colors[16];
    }
    else if (strcmp(name, "Red") == 0) {
        return colors[17];
    }
    else if (strcmp(name, "RedLight") == 0) {
        return colors[18];
    }
    else if (strcmp(name, "Magenta") == 0) {
        return colors[19];
    }
    else if (strcmp(name, "Turquoise") == 0) {
        return colors[20];
    }
    else if (strcmp(name, "Pink") == 0) {
        return colors[21];
    }
    else if (strcmp(name, "Blue") == 0) {
        return colors[22];
    }
    else if (strcmp(name, "BlueLight") == 0) {
        return colors[23];
    }
    else if (strcmp(name, "Orange") == 0) {
        return colors[24];
    }
    else if (strcmp(name, "Green") == 0) {
        return colors[25];
    }
    else if (strcmp(name, "GreenLight") == 0) {
        return colors[26];
    }
    else if (strcmp(name, "Brown") == 0) {
        return colors[27];
    }
    else if (strcmp(name, "Purple") == 0) {
        return colors[28];
    }
    else if (strcmp(name, "BlueishGray") == 0) {
        return colors[29];
    }
    else if (strcmp(name, "Cyan") == 0) {
        return colors[30];
    }else if (strcmp(name, "KDColorBlack") == 0) {
        return colors[31];
    }else if (strcmp(name, "KDColorWhite") == 0) {
        return colors[32];
    }else if (strcmp(name, "KDColorRed") == 0) {
        return colors[33];
    }else if (strcmp(name, "KDColorGreen") == 0) {
        return colors[34];
    }else if (strcmp(name, "KDColorBlue") == 0) {
        return colors[35];
    }else if (strcmp(name, "KDColorYellow") == 0) {
        return colors[36];
    }else if (strcmp(name, "KDColorOrange") == 0) {
        return colors[37];
    }else if (strcmp(name, "KDColorPurple") == 0) {
        return colors[38];
    }else if (strcmp(name, "TextHillightColor") == 0) {
        return colors[39];
    }else if (strcmp(name, "TextColor") == 0) {
        return colors[40];
    }else if (strcmp(name, "BackgroundColor") == 0) {
        return colors[41];
    }else if (strcmp(name, "BackgroundColorHilight") == 0) {
        return colors[42];
    }

    return KDColor::RGB888(255, 255, 255);
};

}