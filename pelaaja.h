#ifndef PELAAJA_H
#define PELAAJA_H

#include <QSet>
#include <QVector>
#include <QMap>
#include "consts.h"
#include "rakennus.h"

class Pelaaja
{
public:
    Pelaaja();
    ~Pelaaja();

    void lisaaDubloneita(unsigned int dublonit);
    void lisaaVoittoPisteita(unsigned int pisteet);
    void lisaaPlantaasi(Plantaasi* temp);
	void lisaaUudisasukas();
	void paivitaResurssit(ResurssiTiedot tiedot);
	void asetaValmius(bool valmiina);

    int palautaDublonit() const;
    int palautaVoittoPisteet() const;
    bool plantaasitTaynna() const;
	int palautaSanJuan() const;
	PelaajaTiedot palautaPelaajaTiedot() const;
	ResurssiTiedot palautaResurssit() const;
	void palautaResurssiLista (QList <Resurssi>& lista) const;
	void palautaTuottavatPlantaasit(QList <Plantaasi*>& lista) const;
	bool palautaValmius() const;
	bool etsiPlantaasi(int id) const;
	void vahennaSanJuan();


private:
    int voittopisteet_;
    int dublonit_;
	int sanJuan_;
	ResurssiTiedot resurssit_;
	bool valmis_;

   QSet <Rakennus*> rakennukset;
   QMap <int,Plantaasi*> pplantaasit;
   QList <Plantaasi*> plantaasit_;
};

#endif // PELAAJA_H
