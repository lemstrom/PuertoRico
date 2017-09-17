#include "majatalo.h"

Majatalo::Majatalo()
{
    hinta_ = 4;
    voittopisteet_ = 2;
}

unsigned int Majatalo::palautaHinta()
{
    return hinta_;
}

unsigned int Majatalo::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Majatalo::tilaaRakennuksissa()
{
    return 0;
}
