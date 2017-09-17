#include "kartano.h"

Kartano::Kartano()
{
    hinta_ = 10;
    voittopisteet_ = 4;
}

unsigned int Kartano::palautaHinta()
{
    return hinta_;
}

unsigned int Kartano::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Kartano::tilaaRakennuksissa()
{
    return 0;
}
