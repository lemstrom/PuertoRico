#ifndef HACIENDA_H
#define HACIENDA_H

#include "../rakennus.h"

class Hacienda : public Rakennus
{
public:
    Hacienda();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // HACIENDA_H
