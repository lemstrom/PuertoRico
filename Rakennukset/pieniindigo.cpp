#include "pieniindigo.h"

PieniIndigo::PieniIndigo()
{
    hinta_ = 1;
    voittopisteet_ = 1;
}

unsigned int PieniIndigo::palautaHinta()
{
    return hinta_;
}

unsigned int PieniIndigo::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int PieniIndigo::tilaaRakennuksissa()
{
    return 0;
}
