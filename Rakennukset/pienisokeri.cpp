#include "pienisokeri.h"

PieniSokeri::PieniSokeri()
{
    hinta_ = 2;
    voittopisteet_ = 1;
}

unsigned int PieniSokeri::palautaHinta()
{
    return hinta_;
}

unsigned int PieniSokeri::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int PieniSokeri::tilaaRakennuksissa()
{
    return 0;
}
