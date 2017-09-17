#ifndef LAITURI_H
#define LAITURI_H

#include "../rakennus.h"

class Laituri : public Rakennus
{
public:
    Laituri();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // LAITURI_H
