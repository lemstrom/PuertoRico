#ifndef KILTATALO_H
#define KILTATALO_H

#include "../rakennus.h"

class Kiltatalo : public Rakennus
{
public:
    Kiltatalo();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // KILTATALO_H
