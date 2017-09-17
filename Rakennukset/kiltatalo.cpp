#include "kiltatalo.h"

Kiltatalo::Kiltatalo()
{
    hinta_ = 10;
    voittopisteet_ = 4;
}

unsigned int Kiltatalo::palautaHinta()
{
    return hinta_;
}

unsigned int Kiltatalo::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Kiltatalo::tilaaRakennuksissa()
{
    return 0;
}
