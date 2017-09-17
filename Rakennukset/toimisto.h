#ifndef TOIMISTO_H
#define TOIMISTO_H

#include "../rakennus.h"

class Toimisto : public Rakennus
{
public:
    Toimisto();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();


private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // TOIMISTO_H
