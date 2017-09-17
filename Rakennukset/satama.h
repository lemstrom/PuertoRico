#ifndef SATAMA_H
#define SATAMA_H

#include "../rakennus.h"

class Satama : public Rakennus
{
public:
    Satama();

    unsigned int palautaHinta();
    unsigned int palautaVoittopisteet();

    unsigned int tilaaRakennuksissa();

private:
    unsigned int hinta_;
    unsigned int voittopisteet_;
};

#endif // SATAMA_H
