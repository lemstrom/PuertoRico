#include "presenter.h"
#include "QDebug"

Presenter::Presenter(IkkunaAPI* ikkuna)
{
    ikkuna_ = ikkuna;
    malli_ = new Pelimalli(this);
}

Presenter::~Presenter()
{

}

void Presenter::rooliValittu(Rooli valinta, unsigned int dublonit, unsigned int uudisasukkaat)
{
	malli_->uusiRooliValittu(valinta,dublonit, uudisasukkaat);
}

int Presenter::vuorossa()
{
	return malli_->vuorossa();
}

Rooli Presenter::nykyinenRooli()
{
	return malli_->nykyinenRooli();
}

void Presenter::siirraVuoro()
{
	malli_->siirraVuoro();
}

bool Presenter::vuorossaPlantaasitTaynna()
{
	return malli_->vuorossaPlantaasitTaynna();
}

void Presenter::plantaasiKlikattu(Plantaasi* plantaasi)
{
	malli_->plantaasiKlikattu(plantaasi);
}

void Presenter::plantaasiTuplaklikattu(Plantaasi* plantaasi)
{
	malli_->plantaasiTuplaklikattu(plantaasi);
}

void Presenter::palautaPlantaasit(QList<Plantaasi*>& plantaasit)
{
	malli_->palautetutPlantaasit(plantaasit);
}

void Presenter::asetaValmius(int pelaaja)
{
	malli_->asetaValmius(pelaaja);
}

void Presenter::aloitaUusiKierros()
{
    ikkuna_->aloitaUusiKierros();
}

void Presenter::paivitaResurssit(ResurssiTiedot pankki, ResurssiTiedot pelaaja1, ResurssiTiedot pelaaja2)
{
	ikkuna_->paivitaResurssit(pankki,pelaaja1,pelaaja2);
}

void Presenter::paivitaPelaajanTiedot(int pelaaja, PelaajaTiedot tiedot)
{
	ikkuna_->paivitaPelaajanTiedot(pelaaja,tiedot);
}

void Presenter::paivitaPlantaasit(int pelaaja)
{
	ikkuna_->paivitaPlantaasit(pelaaja);
}

void Presenter::siirraPlantaasit(QList<Plantaasi*>& plantaasit)
{
	ikkuna_->siirraPlantaasit(plantaasit);
}

void Presenter::uudisraivaajaPaattyy()
{
	ikkuna_->uudisraivaajaPaattyy();
}

void Presenter::pormestariPaattyy()
{
	ikkuna_->pormestariPaattyy();
}

Resurssi Presenter::valitseBonus(QList<Plantaasi*>& lista)
{
	return ikkuna_->valitseBonus(lista);
}

Resurssi Presenter::siirraResurssilista(QList<Resurssi>& resurssit)
{
    return ikkuna_->siirraResurssilista(resurssit);
}

Resurssi Presenter::rahtaaResurssi(QList<Resurssi>& resurssit)
{
    return ikkuna_->rahtaaResurssi(resurssit);
}

void Presenter::tyhjennaKauppa()
{
	ikkuna_->tyhjennaKauppa();
}

void Presenter::paivitaLaivaTilanne(Laivasto tilanne)
{
	ikkuna_->paivitaLaivaTilanne(tilanne);
}

void Presenter::disabloiLouhos()
{
	ikkuna_->disabloiLouhos();
}

void Presenter::vapautaRoolit()
{
	ikkuna_->vapautaRoolit();
}
