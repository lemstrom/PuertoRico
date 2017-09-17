#ifndef KAUPUNGINTALO_H
#define KAUPUNGINTALO_H

#include "../rakennus.h"

class Kaupungintalo : public Rakennus
{
public:
    Kaupungintalo();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // KAUPUNGINTALO_H
