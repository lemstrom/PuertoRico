#ifndef MAJATALO_H
#define MAJATALO_H

#include "../rakennus.h"

class Majatalo : public Rakennus
{
public:
    Majatalo();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // MAJATALO_H
