#include "kaupungintalo.h"

Kaupungintalo::Kaupungintalo()
{
    hinta_ = 10;
    voittopisteet_ = 4;
}

unsigned int Kaupungintalo::palautaHinta()
{
    return hinta_;
}

unsigned int Kaupungintalo::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Kaupungintalo::tilaaRakennuksissa()
{
    return 0;
}
