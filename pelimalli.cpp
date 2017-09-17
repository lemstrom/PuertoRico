#include "pelimalli.h"
#include "QDebug"
//#include <QGlobal.h>
#include <QTime>
#include <QList>
#include <ctime>

Pelimalli::Pelimalli(PresenterAPI* presenter/*, QObject* Parent*/)
{
	//qDebug() << "Rakennetaan malli";

	valintavuoroja_jaljella = 5;
    presenter_ = presenter;
    for(unsigned int i = 0; i < 2; ++i)
    {
        Pelaaja* temp = new Pelaaja();
        pelaajat_.push_back(temp);
    }

    // Luodaan pelin resurssit rakenteeseensa
    resurssit_[MAISSI] = 10;
    resurssit_[INDIGO] = 11;
    resurssit_[SOKERI] = 11;
    resurssit_[TUPAKKA] = 9;
    resurssit_[KAHVI] = 9;

	// Luodaan Plantaasit/louhokset omaan rakenteeseensa (POTENTIAALISESTI OBSOLETE TOIMINNALLISUUS)
    plantaasit_[MAISSI] = 10;
    plantaasit_[INDIGO] = 12;
    plantaasit_[SOKERI] = 11;
    plantaasit_[TUPAKKA] = 9;
    plantaasit_[KAHVI] = 8;
    plantaasit_[LOUHOS] = 8;

	laivat_.laiva1.tyyppi = DUMMY;
	laivat_.laiva1.koko = 6;
	laivat_.laiva1.lasti = 0;
	laivat_.laiva2.tyyppi = DUMMY;
	laivat_.laiva2.koko = 5;
	laivat_.laiva2.lasti = 0;
	laivat_.laiva3.tyyppi = DUMMY;
	laivat_.laiva3.koko = 4;
	laivat_.laiva3.lasti = 0;

	nykyinenRooli_ = EIVALITTU;
	vuoroaJaljella_ = 0;
    kuvernoori_ = 0;
    valintavuorossa_ = 0;
    vuorossa_ = 0;
    plantaasiID_= 0;
	alustaPlantaasit();
	paivitaResurssit();
	paivitaLaivat();
    qDebug() << "Laivat alustettu";
}

Pelimalli::~Pelimalli()
{

}

void Pelimalli::uusiRooliValittu(Rooli valittu, unsigned int dublonit, unsigned int uudisasukkaat)
{
	//qDebug() << "Vuorossa " << vuorossa_ + 1 << "Vuoroa jaljella" << valintavuoroja_jaljella << " Kolikoita oli: " << dublonit;
    pelaajat_.at(vuorossa_)->lisaaDubloneita(dublonit);
	//qDebug() << "Pelaajalla dubloneita " << pelaajat_.at(vuorossa_)->palautaDublonit();
	presenter_->paivitaPelaajanTiedot(vuorossa_,{pelaajat_.at(vuorossa_)->palautaDublonit(),
												 pelaajat_.at(vuorossa_)->palautaVoittoPisteet(),
												 pelaajat_.at(vuorossa_)->palautaSanJuan()});

    switch (valittu) {
    case UUDISRAIVAAJA:
			nykyinenRooli_ = valittu;
			vuoroaJaljella_ = pelaajat_.size();
			if(pelaajat_.at(0)->plantaasitTaynna() and pelaajat_.at(1)->plantaasitTaynna())
			{
				siirraValintaVuoro();
				nykyinenRooli_ = EIVALITTU;
				presenter_->uudisraivaajaPaattyy();
			}
			break;
	case PORMESTARI:
			nykyinenRooli_ = PORMESTARI;
			siirraUudisasukkaatPelaajille(uudisasukkaat);
			paivitaKaikkiPelaajat();
			break;
	case KASITYOLAINEN:
			nykyinenRooli_ = KASITYOLAINEN;
			suoritaKasityolainen();
			siirraValintaVuoro();
			presenter_->vapautaRoolit();
			nykyinenRooli_ = EIVALITTU;
			break;
    case KULLANKAIVAJA:
			pelaajat_.at(vuorossa_)->lisaaDubloneita(1);
			presenter_->paivitaPelaajanTiedot(vuorossa_,{pelaajat_.at(vuorossa_)->palautaDublonit(),
														 pelaajat_.at(vuorossa_)->palautaVoittoPisteet(),
														 pelaajat_.at(vuorossa_)->palautaSanJuan()});
			presenter_->vapautaRoolit();
			siirraValintaVuoro();
			nykyinenRooli_ = EIVALITTU;
			break;
	case KAUPPIAS:
			suoritaKauppias();
			siirraValintaVuoro();
			presenter_->vapautaRoolit();
			nykyinenRooli_ = EIVALITTU;
			break;
	case KAPTEENI:
			suoritaKapteeni();
			siirraValintaVuoro();
			nykyinenRooli_ = EIVALITTU;
			break;
    default:
			nykyinenRooli_ = EIVALITTU;
			presenter_->vapautaRoolit();
			siirraValintaVuoro();
			qDebug() << "Not implemented yet...";
    }


}

int Pelimalli::vuorossa() const
{
	return vuorossa_;
}

Rooli Pelimalli::nykyinenRooli() const
{
	return nykyinenRooli_;
}

bool Pelimalli::vuorossaPlantaasitTaynna() const
{
	return pelaajat_.at(vuorossa_)->plantaasitTaynna();
}

void Pelimalli::siirraVuoro()
{
	//qDebug () << "Vaihdetaan vuoroa, vuorossa oli " << vuorossa_ + 1;
	++vuorossa_;
	if(vuorossa_ == pelaajat_.size())
	{
		vuorossa_ = 0;
	}
	//qDebug() << "Nyt vuorosssa pelaaja " << vuorossa_ + 1;
}

void Pelimalli::palautetutPlantaasit(QList<Plantaasi*>& plantaasit)
{
	palautetutPlantaasit_.append(plantaasit);
	arvoPlantaasit();
}

void Pelimalli::asetaValmius(int pelaaja)
{
	pelaajat_.at(pelaaja)->asetaValmius(true);
	if(pelaajat_.at(0)->palautaValmius() and pelaajat_.at(1)->palautaValmius())
	{
		pormestariPaattyy();
	}
}

void Pelimalli::alustaPlantaasit()
{
	luoPlantaasit(MAISSI,10);
	luoPlantaasit(INDIGO,12);
	luoPlantaasit(SOKERI,11);
	luoPlantaasit(TUPAKKA,9);
	luoPlantaasit(KAHVI,8);
	arvoPlantaasit();
}

void Pelimalli::luoPlantaasit(RaakaAine tyyppi, unsigned int maara)
{
	for(unsigned int i = 0; i < maara; ++i)
	{
		Plantaasi* uusi = new Plantaasi();
		uusi->tyyppi = tyyppi;
		uusi->asetaKuva();
		uusi->id = ++plantaasiID_;
		uusi->omistaja = -1;
		vapaatPlantaasit_ << uusi;
	}
}

void Pelimalli::paivitaResurssit()
{
	qDebug() << "Paivitetaan nakyvat resurtssit";
	ResurssiTiedot tiedot;
	tiedot.maissi = resurssit_.value(MAISSI);
	tiedot.indigo = resurssit_.value(INDIGO);
	tiedot.sokeri = resurssit_.value(SOKERI);
	tiedot.tupakka = resurssit_.value(TUPAKKA);
	tiedot.kahvi = resurssit_.value(KAHVI);
	ResurssiTiedot pelaaja1 = pelaajat_.at(0)->palautaResurssit();
	ResurssiTiedot pelaaja2 = pelaajat_.at(1)->palautaResurssit();
	presenter_->paivitaResurssit(tiedot,pelaaja1,pelaaja2);
}

void Pelimalli::paivitaLaivat()
{
	QPixmap* tempMaissi = new QPixmap( ":Plantaasit/Kuvat/maissi.png" );
	QPixmap* tempIndigo = new QPixmap( ":Plantaasit/Kuvat/indigo.png" );
	QPixmap* tempSokeri = new QPixmap( ":Plantaasit/Kuvat/sokeri.png" );
	QPixmap* tempTupakka = new QPixmap(":Plantaasit/Kuvat/tupakka.png");
	QPixmap* tempKahvi = new QPixmap ( ":Plantaasit/Kuvat/kahvi.png");
	QPixmap* tempDummy = new QPixmap ( ":Plantaasit/Kuvat/dummy.png");

	if(laivat_.laiva1.tyyppi == MAISSI)
	{
		laivat_.laiva1.kuva = tempMaissi;
	}
	else if(laivat_.laiva1.tyyppi == INDIGO)
	{
		laivat_.laiva1.kuva = tempIndigo;
	}
	else if(laivat_.laiva1.tyyppi == SOKERI)
	{
		laivat_.laiva1.kuva = tempSokeri;
	}
	else if(laivat_.laiva1.tyyppi == TUPAKKA)
	{
		laivat_.laiva1.kuva = tempTupakka;
	}
	else if(laivat_.laiva1.tyyppi == KAHVI)
	{
		laivat_.laiva1.kuva = tempKahvi;
	}
	else if(laivat_.laiva1.tyyppi == DUMMY)
	{
		laivat_.laiva1.kuva = tempDummy;
	}

	if(laivat_.laiva2.tyyppi == MAISSI)
	{
		laivat_.laiva2.kuva = tempMaissi;
	}
	else if(laivat_.laiva2.tyyppi == INDIGO)
	{
		laivat_.laiva2.kuva = tempIndigo;
	}
	else if(laivat_.laiva2.tyyppi == SOKERI)
	{
		laivat_.laiva2.kuva = tempSokeri;
	}
	else if(laivat_.laiva2.tyyppi == TUPAKKA)
	{
		laivat_.laiva2.kuva = tempTupakka;
	}
	else if(laivat_.laiva2.tyyppi == KAHVI)
	{
		laivat_.laiva2.kuva = tempKahvi;
	}
	else if(laivat_.laiva2.tyyppi == DUMMY)
	{
		laivat_.laiva2.kuva = tempDummy;
	}

	if(laivat_.laiva3.tyyppi == MAISSI)
	{
		laivat_.laiva3.kuva = tempMaissi;
	}
	else if(laivat_.laiva3.tyyppi == INDIGO)
	{
		laivat_.laiva3.kuva = tempIndigo;
	}
	else if(laivat_.laiva3.tyyppi == SOKERI)
	{
		laivat_.laiva3.kuva = tempSokeri;
	}
	else if(laivat_.laiva3.tyyppi == TUPAKKA)
	{
		laivat_.laiva3.kuva = tempTupakka;
	}
	else if(laivat_.laiva3.tyyppi == KAHVI)
	{
		laivat_.laiva3.kuva = tempKahvi;
	}
	else if(laivat_.laiva3.tyyppi == DUMMY)
	{
		laivat_.laiva3.kuva = tempDummy;
	}

	delete tempMaissi;
	delete tempIndigo;
	delete tempSokeri;
	delete tempTupakka;
	delete tempKahvi;
	delete tempDummy;

	presenter_->paivitaLaivaTilanne(laivat_);
}

void Pelimalli::plantaasiKlikattu(Plantaasi* klikattu)
{
	//qDebug() << "Kuulemma klikattiin jotain plantaasia";

	if(nykyinenRooli_ == UUDISRAIVAAJA)
	{
		presenter_->disabloiLouhos();
		if(pelaajat_.at(vuorossa_)->plantaasitTaynna())
		{
			//qDebug() << "Plantaasille ei ole tilaa";
			// ei voida lisätä uutta plantaasia, jatketaan eteenpäin
			--vuoroaJaljella_;
			if(vuoroaJaljella_ == 0)
			{
				presenter_->uudisraivaajaPaattyy();
				nykyinenRooli_ = EIVALITTU;
				//qDebug() << "Rooli tyhjennetty";
				siirraValintaVuoro();
			}
			else
			{
				siirraVuoro();
			}
			return;
		}

		if(klikattu->tyyppi == LOUHOS)
		{
			klikattu->id = ++plantaasiID_;
		}
		klikattu->omistaja = vuorossa_;
		pelaajat_.at(vuorossa_)->lisaaPlantaasi(klikattu);
		--vuoroaJaljella_;
		//qDebug () << "Uudisraivaajaa jäljellä " << vuoroaJaljella_;
		if(vuoroaJaljella_ == 0)
		{
			presenter_->uudisraivaajaPaattyy();
			nykyinenRooli_ = EIVALITTU;
			//qDebug() << "Rooli tyhjennetty";
			siirraValintaVuoro();
		}
		else
		{
			siirraVuoro();
		}
	}
	else if (nykyinenRooli_ == PORMESTARI)
	{
		//qDebug() << "Kukkuu";
		if(pelaajat_.at(klikattu->omistaja)->etsiPlantaasi(klikattu->id))
		{
			if(pelaajat_.at(klikattu->omistaja)->palautaSanJuan() > 0)
			{
				if(not klikattu->miehitetty)
				{
					//qDebug() << "Miehitellaan plantaasi";
					klikattu->miehitetty = true;
					pelaajat_.at(klikattu->omistaja)->vahennaSanJuan();
				}
				//qDebug() << "Askel 0.1";
				presenter_->paivitaPelaajanTiedot(klikattu->omistaja,pelaajat_.at(klikattu->omistaja)->palautaPelaajaTiedot());
				//qDebug() << "Askel 0.2";
				presenter_->paivitaPlantaasit(klikattu->omistaja);
				//qDebug() << "Askel 0.3";
			}
		}
	}

}

void Pelimalli::plantaasiTuplaklikattu(Plantaasi* klikattu)
{
	//qDebug() << "Tuppeli klikki";
	if(nykyinenRooli_ == PORMESTARI)
	{
		if(pelaajat_.at(klikattu->omistaja)->etsiPlantaasi(klikattu->id))
		{
			qDebug() << "Poistellaan miehitys joka tapauksessa";
			if(klikattu->miehitetty)
			{
				pelaajat_.at(klikattu->omistaja)->lisaaUudisasukas();
			}
			klikattu->miehitetty = false;
			//qDebug() << "Askel 1.1";
			presenter_->paivitaPelaajanTiedot(klikattu->omistaja,pelaajat_.at(klikattu->omistaja)->palautaPelaajaTiedot());
			//qDebug() << "Askel 1.2";
			presenter_->paivitaPlantaasit(klikattu->omistaja);
			//qDebug() << "Askel 1.3";
		}
	}
}

// Private- funktiot

void Pelimalli::uusi_vuoro()
{
	valintavuoroja_jaljella = 5;
    ++kuvernoori_;

    if(kuvernoori_ == pelaajat_.size())
    {
        kuvernoori_ = 0;
    }

	valintavuorossa_ = kuvernoori_;
	vuorossa_ = kuvernoori_;
    presenter_->aloitaUusiKierros();
}

void Pelimalli::siirraValintaVuoro()
{
	++valintavuorossa_;

	if(valintavuorossa_ == pelaajat_.size())
	{
		valintavuorossa_ = 0;
	}

	vuorossa_ = valintavuorossa_;

	if(not --valintavuoroja_jaljella)
	{
		uusi_vuoro();
	}
}

void Pelimalli::pormestariPaattyy()
{
	foreach (Pelaaja* temp, pelaajat_)
	{
		temp->asetaValmius(false);
	}
	siirraValintaVuoro();
	presenter_->pormestariPaattyy();

}

void Pelimalli::siirraUudisasukkaatPelaajille(unsigned int maara)
{
	int temp = vuorossa_;
	pelaajat_.at(temp)->lisaaUudisasukas();
	for(unsigned int i = maara; i > 0; --i)
	{
		pelaajat_.at(temp)->lisaaUudisasukas();
		++temp;
		if(temp == pelaajat_.size())
		{
			temp = 0;
		}
	}

}

void Pelimalli::paivitaKaikkiPelaajat()
{
	for(int i = 0; i < pelaajat_.size(); ++i)
	{
		presenter_->paivitaPelaajanTiedot(i,{pelaajat_.at(i)->palautaDublonit(),
											 pelaajat_.at(i)->palautaVoittoPisteet(),
											 pelaajat_.at(i)->palautaSanJuan()});
	}
}

void Pelimalli::suoritaKasityolainen()
{
	for(int i = 0;i < pelaajat_.size(); ++i)
	{
		QList <Plantaasi*> lista;
		pelaajat_.at(vuorossa_)->palautaTuottavatPlantaasit(lista);
		ResurssiTiedot tiedot = pelaajat_.at(vuorossa_)->palautaResurssit();
		foreach(Plantaasi* temp,lista)
		{
			if(temp->tyyppi == MAISSI and (resurssit_.value(MAISSI) > 0))
			{
				tiedot.maissi += 1;
				resurssit_[MAISSI] = resurssit_.value(MAISSI) - 1;
			}
			else if(temp->tyyppi == INDIGO and (resurssit_.value(INDIGO) > 0))
			{
				tiedot.indigo += 1;
				resurssit_[INDIGO] = resurssit_.value(INDIGO) - 1;
			}
			else if (temp->tyyppi == SOKERI and (resurssit_.value(SOKERI) > 0))
			{
				tiedot.sokeri += 1;
				resurssit_[SOKERI] = resurssit_.value(SOKERI) - 1;
			}
			else if (temp->tyyppi == TUPAKKA and (resurssit_.value(TUPAKKA) > 0))
			{
				tiedot.tupakka += 1;
				resurssit_[TUPAKKA] = resurssit_.value(TUPAKKA) - 1;
			}
			else if (temp->tyyppi == KAHVI and (resurssit_.value(KAHVI) > 0))
			{
				tiedot.kahvi += 1;
				resurssit_[KAHVI] = resurssit_.value(KAHVI) - 1;
			}
		}
		lista.clear();
		pelaajat_.at(vuorossa_)->paivitaResurssit(tiedot);
		siirraVuoro();
	}
	valitseBonusResurssi();
	paivitaResurssit();
}

void Pelimalli::valitseBonusResurssi()
{
	qDebug() << "Bonuksen valitsee pelaaja " << valintavuorossa_ + 1;
	QList <Plantaasi*> lista;
	pelaajat_.at(valintavuorossa_)->palautaTuottavatPlantaasit(lista);
	if(lista.empty())
	{
		qDebug() << "Vastaanotimme empty-listan";
		return;
	}
	// Trimmataan listalta sellaiset resurssit, jotka on jo viety kokonaan
	for (int i = 0; i < lista.size(); ++i)
	{
		//qDebug() << "Trimmaillaan..";
		if(lista.at(i)->tyyppi == MAISSI and (resurssit_.value(MAISSI) < 1))
		{
			lista.removeAt(i);
		}
		else if(lista.at(i)->tyyppi == INDIGO and (resurssit_.value(INDIGO) < 1))
		{
			lista.removeAt(i);
		}
		else if(lista.at(i)->tyyppi == SOKERI and (resurssit_.value(SOKERI) < 1))
		{
			lista.removeAt(i);
		}
		else if(lista.at(i)->tyyppi == TUPAKKA and (resurssit_.value(TUPAKKA) < 1))
		{
			lista.removeAt(i);
		}
		else if(lista.at(i)->tyyppi == KAHVI and (resurssit_.value(KAHVI) < 1))
		{
			lista.removeAt(i);
		}
	}
	//qDebug() << "Trimmailu loppu";
	Resurssi bonus = presenter_->valitseBonus(lista);
	//qDebug() << "Back in malli";
	ResurssiTiedot tiedot = pelaajat_.at(valintavuorossa_)->palautaResurssit();
	if(bonus.aine == MAISSI)
	{
		tiedot.maissi += 1;
		resurssit_[MAISSI] = resurssit_.value(MAISSI) - 1;
	}
	else if(bonus.aine == INDIGO)
	{
		tiedot.indigo += 1;
		resurssit_[INDIGO] = resurssit_.value(INDIGO) - 1;
	}
	else if(bonus.aine == SOKERI)
	{
		tiedot.sokeri += 1;
		resurssit_[SOKERI] = resurssit_.value(SOKERI) - 1;
	}
	else if(bonus.aine == TUPAKKA)
	{
		tiedot.tupakka += 1;
		resurssit_[TUPAKKA] = resurssit_.value(TUPAKKA) - 1;
	}
	else if(bonus.aine == KAHVI)
	{
		tiedot.kahvi += 1;
		resurssit_[KAHVI] = resurssit_.value(KAHVI) - 1;
	}
	pelaajat_.at(valintavuorossa_)->paivitaResurssit(tiedot);
}

void Pelimalli::suoritaKauppias()
{
	QList <Resurssi> resurssit;
	for(int i = 0; i < pelaajat_.size(); ++i)
	{
        resurssit.clear();
		pelaajat_.at(vuorossa_)->palautaResurssiLista(resurssit);
		if(resurssit.empty())
		{
            siirraVuoro();
			continue;
		}
		Resurssi temp = presenter_->siirraResurssilista(resurssit);
		if(temp.aine != DUMMY)
		{
			ResurssiTiedot tiedot = pelaajat_.at(vuorossa_)->palautaResurssit();
			if(temp.aine == MAISSI)
			{
				tiedot.maissi -= 1;
				kauppa_.insert(MAISSI);
			}
			else if(temp.aine == INDIGO)
			{
				tiedot.indigo -= 1;
				kauppa_.insert(INDIGO);
			}
			else if(temp.aine == SOKERI)
			{
				tiedot.sokeri -= 1;
				kauppa_.insert(SOKERI);
			}
			else if(temp.aine == TUPAKKA)
			{
				tiedot.tupakka -= 1;
				kauppa_.insert(TUPAKKA);
			}
			else if(temp.aine == KAHVI)
			{
				tiedot.kahvi -= 1;
				kauppa_.insert(KAHVI);
			}
			pelaajat_.at(vuorossa_)->paivitaResurssit(tiedot);
			pelaajat_.at(vuorossa_)->lisaaDubloneita(static_cast<int>(temp.aine));
		}
		siirraVuoro();

	}
	paivitaKaikkiPelaajat();
	paivitaResurssit();
	qDebug() << "Onko kauppa täyttynyt ?";
	if(kauppa_.size() >= 4)
	{
		qDebug() << "Täynnä on, tyhjennetään";
		foreach(RaakaAine temp, kauppa_)
		{
			if(temp == MAISSI)
			{
				resurssit_[MAISSI] = resurssit_.value(MAISSI) + 1;
			}
			else if (temp == INDIGO)
			{
				resurssit_[INDIGO] = resurssit_.value(INDIGO) + 1;
			}
			else if (temp == SOKERI)
			{
				resurssit_[SOKERI] = resurssit_.value(SOKERI) + 1;
			}
			else if (temp == TUPAKKA)
			{
				resurssit_[TUPAKKA] = resurssit_.value(TUPAKKA) + 1;
			}
			else if (temp == KAHVI)
			{
				resurssit_[KAHVI] = resurssit_.value(KAHVI) + 1;
			}
			else
			{
				qDebug() << "Virheellinen toiminto tapahtui";
			}
		}
		kauppa_.clear();
		presenter_->tyhjennaKauppa();
	}
}

void Pelimalli::suoritaKapteeni()
{
    QList <Resurssi> resurssit;
    while(true)
    {
        resurssit.clear();
        pelaajat_.at(vuorossa_)->palautaResurssiLista(resurssit);
        parsiResurssiLista(resurssit);
        if(resurssit.empty())
        {
            siirraVuoro();
            continue;
        }
        Resurssi temp = presenter_->siirraResurssilista(resurssit);
        if(temp.aine != DUMMY)
        {
            ResurssiTiedot tiedot = pelaajat_.at(vuorossa_)->palautaResurssit();
            if(temp.aine == MAISSI)
            {
                tiedot.maissi -= 1;
                kauppa_.insert(MAISSI);
            }
            else if(temp.aine == INDIGO)
            {
                tiedot.indigo -= 1;
                kauppa_.insert(INDIGO);
            }
            else if(temp.aine == SOKERI)
            {
                tiedot.sokeri -= 1;
                kauppa_.insert(SOKERI);
            }
            else if(temp.aine == TUPAKKA)
            {
                tiedot.tupakka -= 1;
                kauppa_.insert(TUPAKKA);
            }
            else if(temp.aine == KAHVI)
            {
                tiedot.kahvi -= 1;
                kauppa_.insert(KAHVI);
            }
            pelaajat_.at(vuorossa_)->paivitaResurssit(tiedot);
        }
        siirraVuoro();

    }
}

void Pelimalli::parsiResurssiLista(QList<Resurssi> &lista)
{
    for(int i = 0; i < lista.size(); ++i)
    {
        if(laivat_.laiva1.tyyppi != lista.at(i).aine and laivat_.laiva2.tyyppi != lista.at(i).aine and laivat_.laiva3.tyyppi != lista.at(i).aine)
        {
            continue;
        }
        else if (laivat_.laiva1.tyyppi == lista.at(i).aine and (laivat_.laiva1.koko - laivat_.laiva1.lasti) == 0)
        {
            lista.removeAt(i);
        }
        else if (laivat_.laiva2.tyyppi == lista.at(i).aine and (laivat_.laiva2.koko - laivat_.laiva2.lasti) == 0)
        {
            lista.removeAt(i);
        }
        else if (laivat_.laiva3.tyyppi == lista.at(i).aine and (laivat_.laiva3.koko - laivat_.laiva3.lasti) == 0)
        {
            lista.removeAt(i);
        }
    }
}

int Pelimalli::lastaaLaivaan(RaakaAine resurssi, int maara)
{
    int jamat = 0;
    if((laivat_.laiva1.tyyppi == DUMMY and laivat_.laiva2.tyyppi == DUMMY and laivat_.laiva3.tyyppi == DUMMY) or laivat_.laiva1.tyyppi == resurssi)
    {
        laivat_.laiva1.tyyppi = resurssi;
        if((laivat_.laiva1.koko - laivat_.laiva1.lasti) >= maara)
        {
            laivat_.laiva1.lasti += maara;
        }
        else
        {
            jamat = maara - (laivat_.laiva1.koko - laivat_.laiva1.lasti);
            laivat_.laiva1.lasti = laivat_.laiva1.koko;
            return jamat;
        }
    }
    else if((laivat_.laiva2.tyyppi == DUMMY and laivat_.laiva2.tyyppi == DUMMY) or laivat_.laiva2.tyyppi == resurssi)
    {
        laivat_.laiva2.tyyppi = resurssi;
        if((laivat_.laiva2.koko - laivat_.laiva2.lasti) >= maara)
        {
            laivat_.laiva2.lasti += maara;
        }
        else
        {
            jamat = maara - (laivat_.laiva2.koko - laivat_.laiva2.lasti);
            laivat_.laiva2.lasti = laivat_.laiva2.koko;
            return jamat;
        }
    }
    else if(laivat_.laiva3.tyyppi == DUMMY or laivat_.laiva3.tyyppi == resurssi)
    {
        laivat_.laiva3.tyyppi = resurssi;
        if((laivat_.laiva3.koko - laivat_.laiva3.lasti) >= maara)
        {
            laivat_.laiva3.lasti += maara;
        }
        else
        {
            jamat = maara - (laivat_.laiva3.koko - laivat_.laiva3.lasti);
            laivat_.laiva3.lasti = laivat_.laiva3.koko;
            return jamat;
        }
    }
    return jamat;
}

void Pelimalli::arvoPlantaasit()
{
    QList <Plantaasi*> tulos;
    qsrand(time(NULL));
    for(unsigned int i = 0; i < 6; ++i)
    {
		if(vapaatPlantaasit_.empty() and palautetutPlantaasit_.empty())
		{
			break;
		}
		else if(vapaatPlantaasit_.empty())
		{
			vapaatPlantaasit_.append(palautetutPlantaasit_);
			palautetutPlantaasit_.clear();
		}
		int temp = qrand() % vapaatPlantaasit_.size();
		Plantaasi* plantaasi = vapaatPlantaasit_.at(temp);
		vapaatPlantaasit_.removeAt(temp);
		//qDebug() << "Vapaita plantaaseja jaljella: " << vapaatPlantaasit_.size();
		plantaasi->sijainti = i;
        tulos.append(plantaasi);
		//qDebug() << "Arvottiin Plantaasiksi " << plantaasi->tyyppi;
    }
	//qDebug() << "Siiretaan lista ikkunaan";
    presenter_->siirraPlantaasit(tulos);
}
