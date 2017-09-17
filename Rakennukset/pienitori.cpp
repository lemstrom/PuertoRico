#include "pienitori.h"

PieniTori::PieniTori()
{
    hinta_ = 1;
    voittopisteet_ = 1;
}

unsigned int PieniTori::palautaHinta()
{
    return hinta_;
}

unsigned int PieniTori::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int PieniTori::tilaaRakennuksissa()
{
    return 0;
}
