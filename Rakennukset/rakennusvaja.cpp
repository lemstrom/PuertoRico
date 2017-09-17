#include "rakennusvaja.h"

Rakennusvaja::Rakennusvaja()
{
    hinta_ = 2;
    voittopisteet_ = 1;
}

unsigned int Rakennusvaja::palautaHinta()
{
    return hinta_;
}

unsigned int Rakennusvaja::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Rakennusvaja::tilaaRakennuksissa()
{
    return 0;
}
