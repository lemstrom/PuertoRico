#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Gui/guiPlantaasi.h"
#include "Gui/bonusresurssidialogi.h"
#include "Gui/kauppiasdialogi.h"
#include "Gui/kapteenidialogi.h"
#include <QDebug>
#include <QString>
//include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    presenter_ = new Presenter(this);

	// Alustetaan laudan kiinteät kuvaelementit
	// Asetetaan samalla tooltip- tekstit
    qDebug() << "Aloitetaan UI:n tekeminen";
	QPixmap* tempMaissi = new QPixmap( ":Plantaasit/Kuvat/maissi.png" );
	QPixmap* tempIndigo = new QPixmap( ":Plantaasit/Kuvat/indigo.png" );
	QPixmap* tempSokeri = new QPixmap( ":Plantaasit/Kuvat/sokeri.png" );
	QPixmap* tempTupakka = new QPixmap(":Plantaasit/Kuvat/tupakka.png");
	QPixmap* tempKahvi = new QPixmap ( ":Plantaasit/Kuvat/kahvi.png");
	QPixmap* tempDummy = new QPixmap ( ":Plantaasit/Kuvat/dummy.png");
	ui->labelMaissi1->setPixmap(*tempMaissi);
	ui->labelMaissi1->setToolTip("Maissi");
	ui->labelIndigo1->setPixmap(*tempIndigo);
	ui->labelIndigo1->setToolTip("Indigo");
	ui->labelSokeri1->setPixmap(*tempSokeri);
	ui->labelSokeri1->setToolTip("Sokeri");
	ui->labelTupakka1->setPixmap(*tempTupakka);
	ui->labelTupakka1->setToolTip("Tupakka");
	ui->labelKahvi1->setPixmap(*tempKahvi);
	ui->labelKahvi1->setToolTip("Kahvi");
	ui->labelMaissi2->setPixmap(*tempMaissi);
	ui->labelMaissi2->setToolTip("Maissi");
	ui->labelIndigo2->setPixmap(*tempIndigo);
	ui->labelIndigo2->setToolTip("Indigo");
	ui->labelSokeri2->setPixmap(*tempSokeri);
	ui->labelSokeri2->setToolTip("Sokeri");
	ui->labelTupakka2->setPixmap(*tempTupakka);
	ui->labelTupakka2->setToolTip("Tupakka");
	ui->labelKahvi2->setPixmap(*tempKahvi);
	ui->labelKahvi2->setToolTip("Kahvi");
	ui->labelMaissiPankki->setPixmap(*tempMaissi);
	ui->labelMaissiPankki->setToolTip("Maissi");
	ui->labelIndigoPankki->setPixmap(*tempIndigo);
	ui->labelIndigoPankki->setToolTip("Indigo");
	ui->labelSokeriPankki->setPixmap(*tempSokeri);
	ui->labelSokeriPankki->setToolTip("Sokeri");
	ui->labelTupakkaPankki->setPixmap(*tempTupakka);
	ui->labelTupakkaPankki->setToolTip("Tupakka");
	ui->labelKahviPankki->setPixmap(*tempKahvi);
	ui->labelKahviPankki->setToolTip("Kahvi");

	//ui->spinBoxLaiva->setValue(5);
	//disabloiLouhos();

	delete tempMaissi;
	delete tempIndigo;
	delete tempSokeri;
	delete tempTupakka;
	delete tempKahvi;
	delete tempDummy;
	//ui->
    qDebug() << "Mainwindow alustettu";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aloitaUusiKierros()
{
// Lisätään kolikot vielä aktiivisina oleville rooleille
// Lopuksi aktivoidaan kaikki napit uutta vuoroa varten

	//qDebug() << "Aloitellaan uutta rundia";
    if (ui->pushButtonKapteeni->isEnabled())
    {
		qDebug() << "Kapteeni + 1";
        ui->spinBoxKapteeni->setValue((ui->spinBoxKapteeni->value()) + 1);
    }

    if (ui->pushButtonKasityolainen->isEnabled())
    {
        ui->spinBoxKasityolainen->setValue((ui->spinBoxKasityolainen->value()) + 1);
    }

    if (ui->pushButtonKauppias->isEnabled())
    {
        ui->spinBoxKauppias->setValue((ui->spinBoxKauppias->value()) + 1);
    }

    if (ui->pushButtonKullankaivaja1->isEnabled())
    {
        ui->spinBoxKullankaivaja1->setValue((ui->spinBoxKullankaivaja1->value()) + 1);
    }

    if (ui->pushButtonKullankaivaja2->isEnabled())
    {
        ui->spinBoxKullankaivaja2->setValue((ui->spinBoxKullankaivaja2->value()) + 1);
    }

    if (ui->pushButtonPormestari->isEnabled())
    {
        ui->spinBoxPormestari->setValue((ui->spinBoxPormestari->value()) + 1);
    }

    if (ui->pushButtonRakentaja->isEnabled())
    {
        ui->spinBoxRakentaja->setValue((ui->spinBoxRakentaja->value()) + 1);
    }

    if (ui->pushButtonUudisraivaaja->isEnabled())
    {
        ui->spinBoxUudisraivaaja->setValue((ui->spinBoxUudisraivaaja->value()) + 1);
    }

	//qDebug() << "Vapautetaan napit yksitellen";
    ui->pushButtonKapteeni->setEnabled(true);
    ui->pushButtonKasityolainen->setEnabled(true);
    ui->pushButtonKauppias->setEnabled(true);
    ui->pushButtonKullankaivaja1->setEnabled(true);
    ui->pushButtonKullankaivaja2->setEnabled(true);
    ui->pushButtonPormestari->setEnabled(true);
    ui->pushButtonRakentaja->setEnabled(true);
    ui->pushButtonUudisraivaaja->setEnabled(true);
	//qDebug() << "Puhdas vuoro valmiina";
}

void MainWindow::paivitaResurssit(ResurssiTiedot pankki, ResurssiTiedot pelaaja1, ResurssiTiedot pelaaja2)
{
	ui->spinBoxMaissiPankki->setValue(pankki.maissi);
	ui->spinBoxIndigoPankki->setValue(pankki.indigo);
	ui->spinBoxSokeriPankki->setValue(pankki.sokeri);
	ui->spinBoxTupakkaPankki->setValue(pankki.tupakka);
	ui->spinBoxKahviPankki->setValue(pankki.kahvi);
	ui->spinBoxMaissi1->setValue(pelaaja1.maissi);
	ui->spinBoxIndigo1->setValue(pelaaja1.indigo);
	ui->spinBoxSokeri1->setValue(pelaaja1.sokeri);
	ui->spinBoxTupakka1->setValue(pelaaja1.tupakka);
	ui->spinBoxKahvi1->setValue(pelaaja1.kahvi);
	ui->spinBoxMaissi2->setValue(pelaaja2.maissi);
	ui->spinBoxIndigo2->setValue(pelaaja2.indigo);
	ui->spinBoxSokeri2->setValue(pelaaja2.sokeri);
	ui->spinBoxTupakka2->setValue(pelaaja2.tupakka);
	ui->spinBoxKahvi2->setValue(pelaaja2.kahvi);
}

void MainWindow::paivitaPelaajanTiedot(int pelaaja, PelaajaTiedot tiedot)
{
    // Pelaaja-parametri viittaa indeksiin mallin vektorissa
    // Tällöin pelaajanumero on yhtä suurempi
    int temp = pelaaja + 1;

    if(temp == 1)
    {
		//qDebug() << "Päivitetään pelaaja 1";
        ui->spinBoxDublonit1->setValue(tiedot.dublonit);
		ui->spinBoxSanJuan1->setValue(tiedot.sanJuan);
    }
    else if (temp == 2)
    {
		//qDebug() << "Päivitetään pelaaja 2";
        ui->spinBoxDublonit2->setValue(tiedot.dublonit);
		ui->spinBoxSanJuan2->setValue(tiedot.sanJuan);
	}
}

void MainWindow::paivitaPlantaasit(int pelaaja)
{
	//qDebug() << "Suoritamme plantaasien paivityksen ikkunassa";
	if(pelaaja == 0)
	{
		//qDebug() << "Pelaaja 1 plantaasit: " << ui->Plantaasit1->columnCount();
		for(int i = 1; i < ui->Plantaasit1->columnCount(); ++i)
		{
			//guiPlantaasi* temp = NULL;
			//qDebug() << "VAARA!!";
			guiPlantaasi* temp = (guiPlantaasi*) (ui->Plantaasit1->itemAtPosition(0,i)->widget());
			//qDebug() << "Selvisimme vaarasta (kai..)";
			if(temp->palauta_tiedot()->miehitetty)
			{
				temp->asetaReunus(1);
			}
			else
			{
				temp->asetaReunus(0);
			}
		}
	}
	else if(pelaaja == 1)
	{
		for(int i = 1; i < ui->Plantaasit2->columnCount(); ++i)
		{
			guiPlantaasi* temp = NULL;
			temp = (guiPlantaasi*) (ui->Plantaasit2->itemAtPosition(0,i)->widget());
			if(temp->palauta_tiedot()->miehitetty)
			{
				temp->asetaReunus(1);
			}
			else
			{
				temp->asetaReunus(0);
			}
		}
	}
}

void MainWindow::siirraPlantaasit(QList<Plantaasi*>& plantaasit)
{
    //qDebug() << "Paskaa tapahtuu";
    //guiPlantaasi* temp = new guiPlantaasi(Plantaasit.first().kuva,this);
    //ui->Plantaasit->addWidget(temp);

    for(unsigned int i = 0; not plantaasit.empty(); ++i)
    {
		//qDebug() << "Paskaa tapahtuu";
        guiPlantaasi* temp = new guiPlantaasi(plantaasit.first(), this);
		ui->Plantaasit->addWidget(temp,0,i);
        connect(temp,SIGNAL(clicked(Plantaasi*)),this,SLOT(siirraPlantaasiPelaajalle(Plantaasi*)));
		connect(temp,SIGNAL(clicked(Plantaasi*)),this,SLOT(plantaasiKlikattu(Plantaasi*)));
        plantaasit.pop_front();
    }
	 //qDebug() << ui->Plantaasit->columnCount();
	 /*guiPlantaasi* temp = NULL;
	 temp = (guiPlantaasi* ) (ui->horizontalLayout->itemAt(0)->widget());

     if(temp != NULL)
     {
         qDebug() << temp->palautaTyyppi();
	 }*/
}

void MainWindow::uudisraivaajaPaattyy()
{
	qDebug() << "Lopetamme uudisraivaaja - roolin";
	//qDebug() << "Plantaasit size: " << ui->Plantaasit->columnCount();
	QList <Plantaasi*> temp;
	guiPlantaasi* tempp = NULL;
	//while(ui->Plantaasit->itemAtPosition(0,0))
	for(int i = 0; i < 6; ++i)
	{
		//tempp = dynamic_cast<guiPlantaasi*>(ui->Plantaasit->itemAtPosition(0,1)->widget());

		//qDebug() << "VAARA!";
		tempp = (guiPlantaasi*) (ui->Plantaasit->itemAtPosition(0,i)->widget());
		//qDebug() << "Selvisimme vaarasta";
		if(tempp != NULL)
		{
			if(tempp->palautaTyyppi() != DUMMY)
			{
				//qDebug() << "Ei ole dummysta kyse kerralla " << i;
				temp.append(tempp->palauta_tiedot());
			}
			else
			{
				//qDebug() << "Dummy kerralla " << i;
			}

			ui->Plantaasit->removeWidget(tempp);
			delete tempp;
			//qDebug() << "Listassa nyt " << temp.size() << " kohdetta";
		}
	}
	presenter_->palautaPlantaasit(temp);
	//ui->groupBoxPlantaasit->setDisabled(true);
	vapautaRoolit();
}

void MainWindow::pormestariPaattyy()
{
	// TODO: korrekti toteutus puuttuu, mockup tilalla
	ui->Pelaajaroolit->setEnabled(true);
	//qDebug() << "Asetetaan laivaan 5 hemmoa";
	ui->spinBoxLaiva->setValue(5);

}

Resurssi MainWindow::valitseBonus(QList<Plantaasi*>& lista)
{
	Resurssi* resurssi = new Resurssi();
	bonusResurssiDialogi diag(resurssi,lista,this);
	if(diag.exec() == QDialog::Accepted )
	{
		qDebug() << "Finaalissa ?";
		return *resurssi;
	}
	else
	{
		qDebug() << "Ihmeellinen virhe tapahtui";
		Resurssi virhe = {DUMMY};
		return virhe;
	}
}

Resurssi MainWindow::siirraResurssilista(QList<Resurssi>& resurssit)
{
	Resurssi* resurssi = new Resurssi();
    KauppiasDialogi diag(resurssi,resurssit,this);
	if(diag.exec() == QDialog::Accepted)
	{
		//qDebug() << "Finaalissa ?";
		Plantaasi* temp = new Plantaasi{DUMMY,NULL,0,0,false,0};
		temp->tyyppi = resurssi->aine;
		temp->asetaKuva();
		guiPlantaasi* uusi = new guiPlantaasi(temp,this);
		ui->gridLayoutKauppa->addWidget(uusi,0,ui->gridLayoutKauppa->columnCount());
		return *resurssi;
	}
	else
	{
		//qDebug() << "Virhe tapahtui tai pelaaja ei myynyt mitään";
		Resurssi virhe = {DUMMY};
		return virhe;
	}

}

Resurssi MainWindow::rahtaaResurssi(QList<Resurssi>& resurssit)
{
    Resurssi* resurssi = new Resurssi();
    kapteenidialogi diag(resurssi,resurssit,this);
    if(diag.exec() == QDialog::Accepted)
    {
        return *resurssi;
    }
    else
    {
        Resurssi virhe = {DUMMY};
        return virhe;
    }
}

void MainWindow::tyhjennaKauppa()
{
	guiPlantaasi* tempp = NULL;
	qDebug() << "Tyhjennämme kaupan";

	for(int i = 1; i < 5; ++i)
	{
		tempp = (guiPlantaasi*) (ui->gridLayoutKauppa->itemAtPosition(0,i)->widget());
		qDebug() << "Selvisimme vaarasta";
		if(tempp != NULL)
		{
			ui->gridLayoutKauppa->removeWidget(tempp);
			delete tempp;
		}
	}
}

void MainWindow::paivitaLaivaTilanne(Laivasto tilanne)
{
	ui->spinBoxLasti1->setValue(tilanne.laiva1.lasti);
	ui->spinBoxKoko1->setValue(tilanne.laiva1.koko);
	ui->labelTyyppi1->setPixmap(*tilanne.laiva1.kuva);
	ui->spinBoxLasti2->setValue(tilanne.laiva2.lasti);
	ui->spinBoxKoko2->setValue(tilanne.laiva2.koko);
	ui->labelTyyppi2->setPixmap(*tilanne.laiva2.kuva);
	ui->spinBoxLasti3->setValue(tilanne.laiva3.lasti);
	ui->spinBoxKoko3->setValue(tilanne.laiva3.koko);
	ui->labelTyyppi3->setPixmap(*tilanne.laiva3.kuva);
}

void MainWindow::disabloiLouhos()
{
	ui->pushButtonLouhos->setDisabled(true);
}

void MainWindow::vapautaRoolit()
{
	//qDebug() << "Roolit vapaaksi !";
    ui->Pelaajaroolit->setEnabled(true);
}

void MainWindow::siirraPlantaasiPelaajalle(Plantaasi* plantaasi)
{
	//qDebug() << "Siirrellaan pelaajalle plantaasi";

	if(presenter_->nykyinenRooli() != UUDISRAIVAAJA)
    {
        return;
    }
	if(presenter_->vuorossaPlantaasitTaynna())
	{
		//qDebug() << "Vuorossa olijan plantaasit taynna";
		return;
	}

	int vuorossa = presenter_->vuorossa();
	//qDebug() << "Vuorossa: " << vuorossa;
	guiPlantaasi* temp = (guiPlantaasi*) (ui->Plantaasit->itemAtPosition(0,plantaasi->sijainti)->widget());
	ui->Plantaasit->removeWidget(temp);
	Plantaasi* tiedot = new Plantaasi();
	tiedot->tyyppi = DUMMY;
	tiedot->asetaKuva();
	guiPlantaasi* dummy = new guiPlantaasi(tiedot);
	//qDebug() << "Kaaduttaisko?";
	ui->Plantaasit->addWidget(dummy,0,temp->palauta_tiedot()->sijainti);
	//qDebug() << "Selvittiin ehkäpä";

    if(vuorossa == 0)
    {
		ui->Plantaasit1->addWidget(temp,0,ui->Plantaasit1->columnCount());
		//temp->tiedot_->omistaja = 0;
    }
    else if (vuorossa == 1)
    {
		ui->Plantaasit2->addWidget(temp,0,ui->Plantaasit2->columnCount());
    }
	disconnect(temp,SIGNAL(clicked(Plantaasi*)),this,SLOT(siirraPlantaasiPelaajalle(Plantaasi*)));
	connect(temp,SIGNAL(doubleClicked(Plantaasi*)),this,SLOT(plantaasiTuplaklikattu(Plantaasi*)));
}

void MainWindow::plantaasiKlikattu(Plantaasi* plantaasi)
{
	presenter_->plantaasiKlikattu(plantaasi);
}

void MainWindow::plantaasiTuplaklikattu(Plantaasi* plantaasi)
{
	presenter_->plantaasiTuplaklikattu(plantaasi);
}

void MainWindow::on_pushButtonKapteeni_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonKapteeni->setDisabled(true);
    unsigned int kolikot = ui->spinBoxKapteeni->value();
    ui->spinBoxKapteeni->setValue(0);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";

    presenter_->rooliValittu(KAPTEENI,kolikot);
}

void MainWindow::on_pushButtonKasityolainen_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonKasityolainen->setDisabled(true);
    unsigned int kolikot = ui->spinBoxKasityolainen->value();
    ui->spinBoxKasityolainen->setValue(0);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";

    presenter_->rooliValittu(KASITYOLAINEN,kolikot);
}

void MainWindow::on_pushButtonKauppias_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonKauppias->setDisabled(true);
    unsigned int kolikot = ui->spinBoxKauppias->value();
    ui->spinBoxKauppias->setValue(0);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";

    presenter_->rooliValittu(KAUPPIAS,kolikot);
}

void MainWindow::on_pushButtonKullankaivaja1_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonKullankaivaja1->setDisabled(true);
    unsigned int kolikot = ui->spinBoxKullankaivaja1->value();
    ui->spinBoxKullankaivaja1->setValue(0);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";

    presenter_->rooliValittu(KULLANKAIVAJA,kolikot);
}

void MainWindow::on_pushButtonKullankaivaja2_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonKullankaivaja2->setDisabled(true);
    unsigned int kolikot = ui->spinBoxKullankaivaja2->value();
    ui->spinBoxKullankaivaja2->setValue(0);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";

    presenter_->rooliValittu(KULLANKAIVAJA,kolikot);
}

void MainWindow::on_pushButtonPormestari_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonPormestari->setDisabled(true);
    unsigned int kolikot = ui->spinBoxPormestari->value();
    ui->spinBoxPormestari->setValue(0);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";
	ui->pushButtonValmis1->setEnabled(true);
	ui->pushButtonValmis2->setEnabled(true);

	presenter_->rooliValittu(PORMESTARI,kolikot,ui->spinBoxLaiva->value());
}


void MainWindow::on_pushButtonRakentaja_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonRakentaja->setDisabled(true);
    unsigned int kolikot = ui->spinBoxRakentaja->value();
    ui->spinBoxRakentaja->setValue(0);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";

    presenter_->rooliValittu(RAKENTAJA,kolikot);
}

void MainWindow::on_pushButtonUudisraivaaja_clicked()
{
	// Käyttöliittymän päivitys
    ui->pushButtonUudisraivaaja->setDisabled(true);
    unsigned int kolikot = ui->spinBoxUudisraivaaja->value();
	ui->spinBoxUudisraivaaja->setValue(0);
	ui->pushButtonLouhos->setEnabled(true);
	ui->Pelaajaroolit->setDisabled(true);
	//qDebug() << "Disabeloidaan valinnat";

    presenter_->rooliValittu(UUDISRAIVAAJA,kolikot);
}

void MainWindow::on_pushButtonLouhos_clicked()
{
	if(ui->spinBoxLouhos->value())
	{
		ui->spinBoxLouhos->setValue(ui->spinBoxLouhos->value() - 1);
		lisaaLouhosPelaajalle();
	}
}

void MainWindow::lisaaLouhosPelaajalle()
{
	//qDebug() << "Siirrellaan pelaajalle louhos";
	if(presenter_->nykyinenRooli() != UUDISRAIVAAJA)
	{
		return;
	}
	int vuorossa = presenter_->vuorossa();
	//qDebug() << "Vuorossa: " << vuorossa;
	Plantaasi* tiedot = new Plantaasi();
	tiedot->tyyppi = LOUHOS;
	tiedot->asetaKuva();
	tiedot->miehitetty = false;
	tiedot->omistaja = presenter_->vuorossa();
	guiPlantaasi* temp = new guiPlantaasi(tiedot);
	connect(temp,SIGNAL(clicked(Plantaasi*)),this,SLOT(plantaasiKlikattu(Plantaasi*)));

	if(vuorossa == 0)
	{
		ui->Plantaasit1->addWidget(temp,0,ui->Plantaasit1->columnCount());
	}
	else if (vuorossa == 1)
	{
		ui->Plantaasit2->addWidget(temp,0,ui->Plantaasit2->columnCount());
	}
	presenter_->plantaasiKlikattu(tiedot);
}

void MainWindow::on_pushButtonValmis1_clicked()
{
	presenter_->asetaValmius(0);
	ui->pushButtonValmis1->setDisabled(true);
}

void MainWindow::on_pushButtonValmis2_clicked()
{
	presenter_->asetaValmius(1);
	ui->pushButtonValmis2->setDisabled(true);
}


