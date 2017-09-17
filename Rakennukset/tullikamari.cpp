#include "tullikamari.h"

Tullikamari::Tullikamari()
{
    hinta_ = 10;
    voittopisteet_ = 4;
}

unsigned int Tullikamari::palautaHinta()
{
    return hinta_;
}

unsigned int Tullikamari::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Tullikamari::tilaaRakennuksissa()
{
    return 0;
}
