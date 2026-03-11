#ifndef ICON_PROFIL_H
#define ICON_PROFIL_H

#include <escher/image.h>
#include <string.h>

namespace Theme {
class IconProfil{
    public:
        virtual const Escher::Image * getIcon(const char* name) const = 0;
};
}

#endif