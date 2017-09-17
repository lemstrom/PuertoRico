#ifndef PIENIVARASTO_H
#define PIENIVARASTO_H

#include "../rakennus.h"

class PieniVarasto : public Rakennus
{
public:
    PieniVarasto();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // PIENIVARASTO_H
