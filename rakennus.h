#ifndef RAKENNUS_H
#define RAKENNUS_H

class Rakennus
{
public:
    explicit Rakennus() {};
    virtual ~Rakennus() {};

    virtual unsigned int palautaHinta() = 0;
    virtual unsigned int palautaVoittopisteet() = 0;

    virtual unsigned int tilaaRakennuksissa() = 0;
};

#endif // RAKENNUS_H
