#ifndef RAKENNUSVAJA_H
#define RAKENNUSVAJA_H

#include "../rakennus.h"

class Rakennusvaja : public Rakennus
{
public:
    Rakennusvaja();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // RAKENNUSVAJA_H
