#include "suurivarasto.h"

SuuriVarasto::SuuriVarasto()
{
    hinta_ = 6;
    voittopisteet_ = 2;
}

unsigned int SuuriVarasto::palautaHinta()
{
    return hinta_;
}

unsigned int SuuriVarasto::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int SuuriVarasto::tilaaRakennuksissa()
{
    return 0;
}
