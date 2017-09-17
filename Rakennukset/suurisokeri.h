#ifndef SUURISOKERI_H
#define SUURISOKERI_H

#include "../rakennus.h"

class SuuriSokeri : public Rakennus
{
public:
    SuuriSokeri();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // SUURISOKERI_H
