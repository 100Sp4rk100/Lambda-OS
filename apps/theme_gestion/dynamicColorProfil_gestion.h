#ifndef DYNAMIC_COLOR_PROFIL_GESTION_H
#define DYNAMIC_COLOR_PROFIL_GESTION_H

#include <kandinsky/color.h>
#include <ion/storage/file_system.h>
#include "icon_profil.h"

namespace Theme {
class DynamicColorProfilGestion{
    public:
        static KDColor getColor(const char* name);
        static IconProfil* getIconProfil();
        static bool reload();
        static bool isSquareIcon;
        static bool isBackground;
        static int background;
        static bool isDynamicImages;

    private:
        static constexpr int K_MAX_COLORS = 43;
        static KDColor colors[K_MAX_COLORS];
        static int iconProfil;
};
}

#endif