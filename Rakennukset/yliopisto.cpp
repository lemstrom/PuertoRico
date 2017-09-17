#include "yliopisto.h"

Yliopisto::Yliopisto()
{
    hinta_ = 8;
    voittopisteet_ = 3;
}

unsigned int Yliopisto::palautaHinta()
{
    return hinta_;
}

unsigned int Yliopisto::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Yliopisto::tilaaRakennuksissa()
{
    return 0;
}
