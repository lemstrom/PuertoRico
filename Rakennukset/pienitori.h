#ifndef PIENITORI_H
#define PIENITORI_H

#include "../rakennus.h"

class PieniTori : public Rakennus
{
public:
    PieniTori();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // PIENITORI_H
