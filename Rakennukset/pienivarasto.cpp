#include "pienivarasto.h"

PieniVarasto::PieniVarasto()
{
    hinta_ = 3;
    voittopisteet_ = 1;
}

unsigned int PieniVarasto::palautaHinta()
{
    return hinta_;
}

unsigned int PieniVarasto::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int PieniVarasto::tilaaRakennuksissa()
{
    return 0;
}
