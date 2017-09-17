#ifndef LINNOITUS_H
#define LINNOITUS_H

#include "../rakennus.h"

class Linnoitus : public Rakennus
{
public:
    Linnoitus();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // LINNOITUS_H
