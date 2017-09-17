#ifndef KAHVI_H
#define KAHVI_H

#include "../rakennus.h"

class Kahvi : public Rakennus
{
public:
    Kahvi();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // KAHVI_H
