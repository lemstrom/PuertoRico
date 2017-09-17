#include "tehdas.h"

Tehdas::Tehdas()
{
    hinta_ = 7;
    voittopisteet_ = 3;
}

unsigned int Tehdas::palautaHinta()
{
    return hinta_;
}

unsigned int Tehdas::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Tehdas::tilaaRakennuksissa()
{
    return 0;
}
