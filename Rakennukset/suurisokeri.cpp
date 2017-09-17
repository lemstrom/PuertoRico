#include "suurisokeri.h"

SuuriSokeri::SuuriSokeri()
{
    hinta_ = 4;
    voittopisteet_ = 2;
}

unsigned int SuuriSokeri::palautaHinta()
{
    return hinta_;
}

unsigned int SuuriSokeri::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int SuuriSokeri::tilaaRakennuksissa()
{
    return 0;
}
