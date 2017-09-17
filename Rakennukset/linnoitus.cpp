#include "linnoitus.h"

Linnoitus::Linnoitus()
{
    hinta_ = 10;
    voittopisteet_ = 4;
}

unsigned int Linnoitus::palautaHinta()
{
    return hinta_;
}

unsigned int Linnoitus::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Linnoitus::tilaaRakennuksissa()
{
    return 0;
}
