#ifndef CONSTS_H
#define CONSTS_H

#include <QPixmap>

enum Rooli {EIVALITTU,UUDISRAIVAAJA,PORMESTARI,RAKENTAJA,KASITYOLAINEN,KAUPPIAS,KAPTEENI,KULLANKAIVAJA};
enum RaakaAine {MAISSI,INDIGO,SOKERI,TUPAKKA,KAHVI,LOUHOS,DUMMY};

struct PelaajaTiedot{
    int dublonit;
    int voittopisteet;
	int sanJuan;
};

struct Plantaasi{
    RaakaAine tyyppi;
    QPixmap* kuva;
    int sijainti;
    int id;
    bool miehitetty;
	int omistaja;

	~Plantaasi()
	{
		delete kuva;
	}

    void asetaKuva()
    {
		if(this->tyyppi == MAISSI)
        {
            kuva = new QPixmap( ":plantaasit/Kuvat/Plantaasit/maissi.png" );
        }
        else if(this->tyyppi == INDIGO)
        {
            kuva = new QPixmap( ":plantaasit/Kuvat/Plantaasit/indigo.png" );
        }
        else if(this->tyyppi == SOKERI)
        {
            kuva = new QPixmap( ":plantaasit/Kuvat/Plantaasit/sokeri.png" );
        }
        else if(this->tyyppi == TUPAKKA)
        {
            kuva = new QPixmap( ":plantaasit/Kuvat/Plantaasit/tupakka.png" );
        }
        else if(this->tyyppi == KAHVI)
        {
            kuva = new QPixmap( ":plantaasit/Kuvat/Plantaasit/kahvi.png" );
        }
        else if(this->tyyppi == LOUHOS)
        {
            kuva = new QPixmap( ":plantaasit/Kuvat/Plantaasit/louhos.png" );
        }
		else if(this->tyyppi == DUMMY)
		{
            kuva = new QPixmap( ":plantaasit/Kuvat/Plantaasit/dummy.png" );
		}
    }
};

struct ResurssiTiedot{
	int maissi;
	int indigo;
	int sokeri;
	int tupakka;
	int kahvi;
};

struct Resurssi{
	RaakaAine aine;
};

struct Rahtilaiva{
	RaakaAine tyyppi;
	int koko;
	int lasti;
	QPixmap* kuva;
};

struct Laivasto{
	Rahtilaiva laiva1;
	Rahtilaiva laiva2;
	Rahtilaiva laiva3;
};

#endif // CONSTS_H
