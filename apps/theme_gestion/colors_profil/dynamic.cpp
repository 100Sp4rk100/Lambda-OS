#include "dynamic.h"

#include "../dynamicColorProfil_gestion.h"

namespace Theme {

KDColor DynamicColorProfil::getColor(const char* name) const{
    return Theme::DynamicColorProfilGestion::getColor(name);
}

}
