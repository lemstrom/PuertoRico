#ifndef PELIMALLI_H
#define PELIMALLI_H

#include "consts.h"
#include "PresenterAPI.h"
#include "pelaaja.h"
#include "QVector"
#include "QMap"
#include "QSet"

class Pelimalli
{

public:
	Pelimalli(PresenterAPI* presenter);
    ~Pelimalli();

	// Presenterin rajapinta malliin päin
	void uusiRooliValittu(Rooli valittu, unsigned int dublonit, unsigned int uudisasukkaat);
    int vuorossa() const;
	Rooli nykyinenRooli() const;
	bool vuorossaPlantaasitTaynna() const;
	void siirraVuoro();
	void plantaasiKlikattu(Plantaasi* klikattu);
	void plantaasiTuplaklikattu(Plantaasi* klikattu);
	void palautetutPlantaasit(QList <Plantaasi*>& plantaasit);
	void asetaValmius(int pelaaja);

private:

	void alustaPlantaasit();
	void luoPlantaasit(RaakaAine tyyppi, unsigned int maara);
	void paivitaResurssit();
	void paivitaLaivat();

    void uusi_vuoro();
	void siirraValintaVuoro();

	void pormestariPaattyy();

    // Roolien toiminnot
	void siirraUudisasukkaatPelaajille(unsigned int maara);
	void paivitaKaikkiPelaajat();
	void suoritaKasityolainen();
	void valitseBonusResurssi();
	void suoritaKauppias();
	void suoritaKapteeni();
    void parsiResurssiLista (QList <Resurssi>& lista);
    int lastaaLaivaan(RaakaAine resurssi, int maara);

    void arvoPlantaasit();

	Rooli nykyinenRooli_;
	int vuoroaJaljella_;
	int valintavuoroja_jaljella;
    int kuvernoori_;
    int valintavuorossa_;
    int vuorossa_;
    int plantaasiID_;

    QVector <Pelaaja*> pelaajat_;
	QList <Plantaasi*> vapaatPlantaasit_;
	QList <Plantaasi*> palautetutPlantaasit_;
	QSet <RaakaAine> kauppa_;
	Laivasto laivat_;

    QMap <RaakaAine,int> resurssit_;
    QMap <RaakaAine,int> plantaasit_;

    PresenterAPI* presenter_;
};

#endif // PELIMALLI_H
