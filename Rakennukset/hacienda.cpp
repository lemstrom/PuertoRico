#include "hacienda.h"

Hacienda::Hacienda()
{
    hinta_ = 2;
    voittopisteet_ = 1;
}

unsigned int Hacienda::palautaHinta()
{
    return hinta_;
}

unsigned int Hacienda::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Hacienda::tilaaRakennuksissa()
{
    return 0;
}
