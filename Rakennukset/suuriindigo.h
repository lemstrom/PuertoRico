#ifndef SUURIINDIGO_H
#define SUURIINDIGO_H

#include "../rakennus.h"

class SuuriIndigo: public Rakennus
{
public:
    SuuriIndigo();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // SUURIINDIGO_H
