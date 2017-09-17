#ifndef SUURIVARASTO_H
#define SUURIVARASTO_H

#include "../rakennus.h"

class SuuriVarasto : public Rakennus
{
public:
    SuuriVarasto();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();


private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // SUURIVARASTO_H
