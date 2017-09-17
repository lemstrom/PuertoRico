#include "kahvi.h"

Kahvi::Kahvi()
{
    hinta_ = 6;
    voittopisteet_ = 3;
}

unsigned int Kahvi::palautaHinta()
{
    return hinta_;
}

unsigned int Kahvi::palautaVoittopisteet()
{
    return voittopisteet_;
}

unsigned int Kahvi::tilaaRakennuksissa()
{
    return 0;
}
