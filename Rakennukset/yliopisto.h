#ifndef YLIOPISTO_H
#define YLIOPISTO_H

#include "../rakennus.h"

class Yliopisto : public Rakennus
{
public:
    Yliopisto();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();


private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // YLIOPISTO_H
