#ifndef KARTANO_H
#define KARTANO_H

#include "../rakennus.h"

class Kartano : public Rakennus
{
public:
    Kartano();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // KARTANO_H
