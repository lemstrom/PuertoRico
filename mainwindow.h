#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "presenter.h"
#include "IkkunaAPI.h"
#include "consts.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IkkunaAPI
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void aloitaUusiKierros();
	void paivitaResurssit(ResurssiTiedot pankki, ResurssiTiedot pelaaja1, ResurssiTiedot pelaaja2);
	void paivitaPelaajanTiedot (int pelaaja, PelaajaTiedot tiedot);
	void paivitaPlantaasit(int pelaaja);
    void siirraPlantaasit (QList <Plantaasi*>& plantaasit);
	void uudisraivaajaPaattyy();
	void pormestariPaattyy();
	Resurssi valitseBonus(QList <Plantaasi*>& lista);
	Resurssi siirraResurssilista(QList <Resurssi>& resurssit);
    Resurssi rahtaaResurssi (QList <Resurssi>& resurssit);
	void tyhjennaKauppa();
	void paivitaLaivaTilanne(Laivasto tilanne);
	void disabloiLouhos();
    void vapautaRoolit();

public slots:
    void siirraPlantaasiPelaajalle(Plantaasi* plantaasi);
	void plantaasiKlikattu(Plantaasi* plantaasi);
	void plantaasiTuplaklikattu(Plantaasi* plantaasi);

private slots:
    void on_pushButtonKapteeni_clicked();
    void on_pushButtonKasityolainen_clicked();
    void on_pushButtonKauppias_clicked();
    void on_pushButtonKullankaivaja1_clicked();
    void on_pushButtonKullankaivaja2_clicked();
    void on_pushButtonRakentaja_clicked();
    void on_pushButtonPormestari_clicked();
    void on_pushButtonUudisraivaaja_clicked();


	void on_pushButtonLouhos_clicked();
	void on_pushButtonValmis1_clicked();
	void on_pushButtonValmis2_clicked();


private:
    Ui::MainWindow *ui;


	void lisaaLouhosPelaajalle();

    Presenter* presenter_;

};

#endif // MAINWINDOW_H
