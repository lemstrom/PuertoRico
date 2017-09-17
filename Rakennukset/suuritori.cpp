#include "suuritori.h"

SuuriTori::SuuriTori()
{
    hinta_ = 5;
    voittopisteet_ = 2;
}

unsigned int SuuriTori::palautaHinta()
{
    return hinta_;
}

unsigned int SuuriTori::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int SuuriTori::tilaaRakennuksissa()
{
    return 0;
}
