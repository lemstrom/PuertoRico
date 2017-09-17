#ifndef PIENIINDIGO_H
#define PIENIINDIGO_H

#include "../rakennus.h"

class PieniIndigo: public Rakennus
{
public:
    PieniIndigo();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // PIENIINDIGO_H
