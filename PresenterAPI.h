#ifndef PRESENTERAPI_H
#define PRESENTERAPI_H

#include "consts.h"
#include <QList>

// rajapintaluokka pelimalli-luokalle Presenterin suuntaan
class PresenterAPI
{
public:
    virtual void aloitaUusiKierros() = 0;
	virtual void paivitaResurssit(ResurssiTiedot pankki, ResurssiTiedot pelaaja1, ResurssiTiedot pelaaja2) = 0;
	virtual void paivitaPelaajanTiedot (int pelaaja, PelaajaTiedot tiedot) = 0;
	virtual void paivitaPlantaasit (int pelaaja) = 0;
    virtual void siirraPlantaasit (QList <Plantaasi*>& plantaasit) = 0;
	virtual void uudisraivaajaPaattyy() = 0;
	virtual void pormestariPaattyy() = 0;
	virtual Resurssi valitseBonus(QList <Plantaasi*>& lista) = 0;
	virtual Resurssi siirraResurssilista(QList <Resurssi>& resurssit) = 0;
    virtual Resurssi rahtaaResurssi (QList <Resurssi>& resurssit) = 0;
	virtual void tyhjennaKauppa() = 0;
	virtual void paivitaLaivaTilanne(Laivasto tilanne) = 0;
	virtual void disabloiLouhos() = 0;
	virtual void vapautaRoolit() = 0;
};

#endif // PRESENTERAPI_H
