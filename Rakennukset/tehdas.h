#ifndef TEHDAS_H
#define TEHDAS_H

#include "../rakennus.h"

class Tehdas : public Rakennus
{
public:
    Tehdas();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();


private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // TEHDAS_H
