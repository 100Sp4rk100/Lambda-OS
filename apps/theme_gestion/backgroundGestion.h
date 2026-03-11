#ifndef BACKGROUNDGESTION_H
#define BACKGROUNDGESTION_H

#include <stdint.h>

#include "background/background_lambda_classic.h"
#include "background/background_lambda_2.h"
#include "background/background_blossom.h"
#include "background/background_town.h"

#include "background/customs_backgrounds.h"

extern int background_width;
extern int background_height;

namespace Background {

class BackgroundGestion{

    public:
        static const uint16_t* getBackgroundNumber(int n);

    private:
        static int current;

        static constexpr int NB_BACKGROUNDS = 4;
        static const uint16_t* background_list[NB_BACKGROUNDS];
};

}

#endif