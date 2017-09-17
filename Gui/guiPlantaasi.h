#ifndef GUIPlantaasi_H
#define GUIPlantaasi_H

#include <consts.h>
#include <QWidget>
#include <QPixmap>


namespace Ui {
class guiPlantaasi;
}

class guiPlantaasi : public QWidget
{
    Q_OBJECT

public:
    explicit guiPlantaasi(Plantaasi* tiedot, QWidget *parent = 0);
    ~guiPlantaasi();

    RaakaAine palautaTyyppi();
	Plantaasi* palauta_tiedot();
	void asetaReunus(int paalle);

signals:
    void clicked(Plantaasi* tiedot);
	void doubleClicked(Plantaasi* tiedot);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);


private:
    //void emitClicked();

    Ui::guiPlantaasi *ui;

    void asetaKuva(QPixmap* kuva);

    Plantaasi* tiedot_;
    //guiPlantaasiAPI* ikkuna_;


};

#endif // GUIPlantaasi_H
