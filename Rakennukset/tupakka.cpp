#include "tupakka.h"

Tupakka::Tupakka()
{
    hinta_ = 5;
    voittopisteet_ = 3;
}

unsigned int Tupakka::palautaHinta()
{
    return hinta_;
}

unsigned int Tupakka::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Tupakka::tilaaRakennuksissa()
{
    return 0;
}
