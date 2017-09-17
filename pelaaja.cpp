#include "pelaaja.h"
#include "QDebug"

Pelaaja::Pelaaja()
{
    voittopisteet_ = 0;
    dublonit_ = 0;
	sanJuan_ = 0;
	resurssit_.maissi = 0;
	resurssit_.indigo = 0;
	resurssit_.sokeri = 0;
	resurssit_.tupakka = 0;
	resurssit_.kahvi = 0;
	valmis_ = false;
}

Pelaaja::~Pelaaja()
{

}

void Pelaaja::lisaaDubloneita(unsigned int dublonit)
{
    dublonit_ += dublonit;
}

void Pelaaja::lisaaVoittoPisteita(unsigned int pisteet)
{
	voittopisteet_ += pisteet;
}

void Pelaaja::lisaaPlantaasi(Plantaasi* temp)
{
	plantaasit_.push_back(temp);
	pplantaasit.insert(temp->id,temp);
}

void Pelaaja::lisaaUudisasukas()
{
	++sanJuan_;
}

void Pelaaja::paivitaResurssit(ResurssiTiedot tiedot)
{
	qDebug() << "Paivitellaan resursseja...";
	qDebug() << "Vanhat:";
	qDebug() << "Maissi: " << resurssit_.maissi << ", Indigo: " << resurssit_.indigo << ", Sokeri: " << resurssit_.sokeri << ", Tupakka: " << resurssit_.tupakka
			 << ", Kahvi: " << resurssit_.kahvi;
	qDebug() << "Uudet:";
	qDebug() << "Maissi: " << tiedot.maissi << ", Indigo: " << tiedot.indigo << ", Sokeri: " << tiedot.sokeri << ", Tupakka: " << tiedot.tupakka
			 << ", Kahvi: " << tiedot.kahvi;
	resurssit_ = tiedot;
}

void Pelaaja::asetaValmius(bool valmiina)
{
	valmis_ = valmiina;
}

int Pelaaja::palautaDublonit() const
{
    return dublonit_;
}

int Pelaaja::palautaVoittoPisteet() const
{
    return voittopisteet_;
}

bool Pelaaja::plantaasitTaynna() const
{
	return plantaasit_.size() == 12;
}

int Pelaaja::palautaSanJuan() const
{
	return sanJuan_;
}

PelaajaTiedot Pelaaja::palautaPelaajaTiedot() const
{
	return {dublonit_,voittopisteet_,sanJuan_};
}

ResurssiTiedot Pelaaja::palautaResurssit() const
{
	return resurssit_;
}

void Pelaaja::palautaResurssiLista(QList<Resurssi>& lista) const
{
	lista.clear();
	Resurssi temp;
	if(resurssit_.maissi > 0)
	{
		temp.aine = MAISSI;
		lista.append(temp);
	}
	if(resurssit_.indigo > 0)
	{
		temp.aine = INDIGO;
		lista.append(temp);
	}
	if(resurssit_.sokeri > 0)
	{
		temp.aine = SOKERI;
		lista.append(temp);
	}
	if(resurssit_.tupakka > 0)
	{
		temp.aine = TUPAKKA;
		lista.append(temp);
	}
	if(resurssit_.kahvi > 0)
	{
		temp.aine = KAHVI;
		lista.append(temp);
	}
}

void Pelaaja::palautaTuottavatPlantaasit(QList<Plantaasi*>& lista) const
{
	foreach(int id,pplantaasit.keys())
	{
		if(pplantaasit.value(id)->miehitetty)
		{
			lista.append(pplantaasit.value(id));
		}
	}
	qDebug() << "Palautamme listan, jossa seuraavat plantaasit: ";
	foreach (Plantaasi* temp, lista)
	{
		qDebug() << temp->tyyppi;
	}
}

bool Pelaaja::palautaValmius() const
{
	return valmis_;
}

bool Pelaaja::etsiPlantaasi(int id) const
{
	return pplantaasit.contains(id);
}

void Pelaaja::vahennaSanJuan()
{
	if(sanJuan_ > 0)
	{
		--sanJuan_;
	}
}
