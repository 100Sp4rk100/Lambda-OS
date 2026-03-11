#ifndef COLOR_PROFIL_H
#define COLOR_PROFIL_H

#include <kandinsky/color.h>
#include <escher/palette.h>
#include <string.h>

namespace Theme {
class ColorProfil{
    public:
        virtual KDColor getColor(const char* name) const = 0;
};
}

#endif