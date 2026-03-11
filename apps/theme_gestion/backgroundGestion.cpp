#include "backgroundGestion.h"

int background_width = 320;
int background_height = 240;

namespace Background {

int BackgroundGestion::current = 0;

const uint16_t* BackgroundGestion::background_list[NB_BACKGROUNDS] = {
    background_lambda_classic,
    background_lambda_2,
    background_town,
    background_blossom
};

const uint16_t* BackgroundGestion::getBackgroundNumber(int n) {

    if (n<0 || n>=(NB_BACKGROUNDS + NB_BACKGROUNDS_CUSTOM)) return nullptr;
    

    if (n < NB_BACKGROUNDS) {
        return background_list[n];
    }else{
        return background_list_custom[n-NB_BACKGROUNDS];
    }

    return nullptr;
}

}