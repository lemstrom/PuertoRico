#include "suuriindigo.h"

SuuriIndigo::SuuriIndigo()
{
    hinta_ = 3;
    voittopisteet_ = 2;
}

unsigned int SuuriIndigo::palautaHinta()
{
    return hinta_;
}

unsigned int SuuriIndigo::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int SuuriIndigo::tilaaRakennuksissa()
{
    return 0;
}
