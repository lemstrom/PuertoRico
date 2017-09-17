#ifndef PIENISOKERI_H
#define PIENISOKERI_H

#include "../rakennus.h"

class PieniSokeri : public Rakennus
{
public:
    PieniSokeri();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // PIENISOKERI_H
