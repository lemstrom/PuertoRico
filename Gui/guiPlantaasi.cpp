#include "guiPlantaasi.h"
#include "ui_guiPlantaasi.h"
#include <QDebug>

guiPlantaasi::guiPlantaasi(Plantaasi* tiedot, QWidget* parent) : QWidget(parent), ui(new Ui::guiPlantaasi)
{
    ui->setupUi(this);
	//qDebug() << "Rakennettiin guiPlantaasi";
    tiedot_ = tiedot;
    tiedot_->miehitetty = false;
    //ikkuna_ = ikkuna;
    asetaKuva(tiedot_->kuva);
}

guiPlantaasi::~guiPlantaasi()
{
	delete tiedot_;
    delete ui;
}

RaakaAine guiPlantaasi::palautaTyyppi()
{
	return tiedot_->tyyppi;
}

Plantaasi*guiPlantaasi::palauta_tiedot()
{
	return tiedot_;
}

void guiPlantaasi::asetaReunus(int paalle)
{
	ui->Kuva->setFrameStyle(paalle);
}

void guiPlantaasi::mousePressEvent(QMouseEvent *)
{
	//qDebug() << "Klikkaus!";
	emit(clicked(tiedot_));
}

void guiPlantaasi::mouseDoubleClickEvent(QMouseEvent *)
{
	//qDebug() << "Tuplaklikkaus!";
	emit(doubleClicked(tiedot_));
}

void guiPlantaasi::asetaKuva(QPixmap* kuva)
{
    ui->Kuva->setPixmap(*kuva);
}

/*void guiPlantaasi::emitClicked()
{
    emit(clicked(tiedot_));
}
*/
