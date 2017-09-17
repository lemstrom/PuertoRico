#ifndef GUIRAKENNUS_H
#define GUIRAKENNUS_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class guiRakennus;
}

class guiRakennus : public QWidget
{
    Q_OBJECT

public:
    explicit guiRakennus(QPixmap* kuva, QWidget* parent = 0);
    ~guiRakennus();


protected:
    void mousePressEvent(QMouseEvent *);

private:

    Ui::guiRakennus* ui;

    void asetaKuva(QPixmap* kuva);
};

#endif // GUIRAKENNUS_H
