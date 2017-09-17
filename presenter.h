#ifndef PRESENTER_H
#define PRESENTER_H

#include "pelimalli.h"
#include "consts.h"
#include "PresenterAPI.h"
#include "IkkunaAPI.h"
#include "Gui/guiPlantaasi.h"


class Presenter : public PresenterAPI
{

public:
    Presenter(IkkunaAPI* ikkuna);
    ~Presenter();

    // Mainwindow -> Pelimalli -liikenne
	void rooliValittu (Rooli valinta, unsigned int dublonit, unsigned int uudisasukkaat = 0);
    int vuorossa();
	Rooli nykyinenRooli();
    void siirraVuoro();
	bool vuorossaPlantaasitTaynna();
	void plantaasiKlikattu(Plantaasi* plantaasi);
	void plantaasiTuplaklikattu(Plantaasi* plantaasi);
	void palautaPlantaasit(QList <Plantaasi*>& plantaasit);
	void asetaValmius(int pelaaja);

    // Pelimalli -> Mainwindow -liikenne
    void aloitaUusiKierros();
	void paivitaResurssit(ResurssiTiedot pankki, ResurssiTiedot pelaaja1, ResurssiTiedot pelaaja2);
    void paivitaPelaajanTiedot (int pelaaja, PelaajaTiedot tiedot);
	void paivitaPlantaasit (int pelaaja);
    void siirraPlantaasit (QList <Plantaasi*>& plantaasit);
	void uudisraivaajaPaattyy();
	void pormestariPaattyy();
	Resurssi valitseBonus(QList <Plantaasi*>& lista);
	Resurssi siirraResurssilista(QList <Resurssi>& resurssit);
    Resurssi rahtaaResurssi(QList <Resurssi>& resurssit);
	void tyhjennaKauppa();
	void paivitaLaivaTilanne(Laivasto tilanne);
	void disabloiLouhos();
	void vapautaRoolit();


private:
    Pelimalli* malli_;
    IkkunaAPI* ikkuna_;
};

#endif // PRESENTER_H
