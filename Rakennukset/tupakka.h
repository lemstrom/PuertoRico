#ifndef TUPAKKA_H
#define TUPAKKA_H

#include "../rakennus.h"

class Tupakka : public Rakennus
{
public:
    Tupakka();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();


private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // TUPAKKA_H
