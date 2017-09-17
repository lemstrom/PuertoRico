#ifndef SUURITORI_H
#define SUURITORI_H

#include "../rakennus.h"

class SuuriTori : public Rakennus
{
public:
    SuuriTori();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();


private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // SUURITORI_H
