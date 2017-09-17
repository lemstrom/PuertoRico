#include "bonusresurssidialogi.h"
#include "ui_bonusresurssidialogi.h"
#include "QDebug"

bonusResurssiDialogi::bonusResurssiDialogi(Resurssi* resurssi, QList<Plantaasi*>& lista, QWidget *parent) : QDialog(parent), ui(new Ui::bonusResurssiDialogi)
{
	// Tyhjän listan tapauksessa ei tehdä mitään
	if(lista.length() == 0)
	{
		resurssi->aine = DUMMY;
		accept();
	}
	ui->setupUi(this);
	resurssi_ = resurssi;
	foreach(Plantaasi* temp, lista)
	{
		if(temp->tyyppi == MAISSI and ui->comboBoxResurssit->findText("Maissi") == -1)
		{
			ui->comboBoxResurssit->addItem("Maissi");
		}
		else if (temp->tyyppi == INDIGO and ui->comboBoxResurssit->findText("Indigo") == -1)
		{
			ui->comboBoxResurssit->addItem("Indigo");
		}
		else if (temp->tyyppi == SOKERI and ui->comboBoxResurssit->findText("Sokeri") == -1)
		{
			ui->comboBoxResurssit->addItem("Sokeri");
		}
		else if (temp->tyyppi == TUPAKKA and ui->comboBoxResurssit->findText("Tupakka") == -1)
		{
			ui->comboBoxResurssit->addItem("Tupakka");
		}
		else if (temp->tyyppi == KAHVI and ui->comboBoxResurssit->findText("Kahvi") == -1)
		{
			ui->comboBoxResurssit->addItem("Kahvi");
		}
	}
}

bonusResurssiDialogi::~bonusResurssiDialogi()
{
	delete ui;
}

void bonusResurssiDialogi::on_buttonBox_accepted()
{
	qDebug() << "Valinta on tehty, aloitamme poistumisen, valintana on: " << ui->comboBoxResurssit->currentText();
	if(ui->comboBoxResurssit->currentText() == "Maissi")
	{
		resurssi_->aine = MAISSI;
	}
	else if(ui->comboBoxResurssit->currentText() == "Indigo")
	{
		resurssi_->aine = INDIGO;
	}
	else if(ui->comboBoxResurssit->currentText() == "Sokeri")
	{
		resurssi_->aine = SOKERI;
	}
	else if(ui->comboBoxResurssit->currentText() == "Tupakka")
	{
		resurssi_->aine = TUPAKKA;
	}
	else if(ui->comboBoxResurssit->currentText() == "Kahvi")
	{
		resurssi_->aine = KAHVI;
	}
	qDebug() << "Poistumme siis dialogista";
}
