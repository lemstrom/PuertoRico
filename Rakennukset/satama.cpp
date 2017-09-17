#include "satama.h"

Satama::Satama()
{
    hinta_ = 8;
    voittopisteet_ = 3;
}

unsigned int Satama::palautaHinta()
{
    return hinta_;
}

unsigned int Satama::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Satama::tilaaRakennuksissa()
{
    return 0;
}
