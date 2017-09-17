#include "kapteenidialogi.h"
#include "ui_kapteenidialogi.h"
#include "QDebug"

kapteenidialogi::kapteenidialogi(Resurssi* resurssi, QList<Resurssi>& lista, QWidget *parent) : QDialog(parent), ui(new Ui::kapteenidialogi)
{	
	if(lista.empty())
	{
		resurssi->aine = DUMMY;
		reject();
	}
	ui->setupUi(this);
	resurssi_ = resurssi;
	foreach(Resurssi temp, lista)
	{
		if(temp.aine == MAISSI)
		{
			ui->comboBoxResurssit->addItem("Maissi");
		}
		else if (temp.aine == INDIGO)
		{
			ui->comboBoxResurssit->addItem("Indigo");
		}
		else if (temp.aine == SOKERI)
		{
			ui->comboBoxResurssit->addItem("Sokeri");
		}
		else if (temp.aine == TUPAKKA)
		{
			ui->comboBoxResurssit->addItem("Tupakka");
		}
		else if (temp.aine == KAHVI)
		{
			ui->comboBoxResurssit->addItem("Kahvi");
		}
	}
}

kapteenidialogi::~kapteenidialogi()
{
	delete ui;
}

void kapteenidialogi::on_buttonBox_accepted()
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
