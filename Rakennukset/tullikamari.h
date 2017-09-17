#ifndef TULLIKAMARI_H
#define TULLIKAMARI_H

#include "../rakennus.h"

class Tullikamari : public Rakennus
{
public:
    Tullikamari();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();


private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // TULLIKAMARI_H
