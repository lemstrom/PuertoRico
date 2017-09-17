#include "laituri.h"

Laituri::Laituri()
{
    hinta_ = 9;
    voittopisteet_ = 3;
}

unsigned int Laituri::palautaHinta()
{
    return hinta_;
}

unsigned int Laituri::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Laituri::tilaaRakennuksissa()
{
    return 0;
}
