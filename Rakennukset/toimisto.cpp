#include "toimisto.h"

Toimisto::Toimisto()
{
    hinta_ = 5;
    voittopisteet_ = 2;
}

unsigned int Toimisto::palautaHinta()
{
    return hinta_;
}

unsigned int Toimisto::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Toimisto::tilaaRakennuksissa()
{
    return 0;
}
