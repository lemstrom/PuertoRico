#include "guirakennus.h"
#include "ui_guirakennus.h"

guiRakennus::guiRakennus(QPixmap* kuva, QWidget *parent): QWidget(parent), ui(new Ui::guiRakennus)
{
    ui->setupUi(this);
    asetaKuva(kuva);
}

guiRakennus::~guiRakennus()
{
    delete ui;
}

void guiRakennus::asetaKuva(QPixmap *kuva)
{
    ui->Kuva->setPixmap(*kuva);
}

void guiRakennus::mousePressEvent(QMouseEvent *)
{

}
