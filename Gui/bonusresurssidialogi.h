#ifndef BONUSRESURSSIDIALOGI_H
#define BONUSRESURSSIDIALOGI_H

#include <QDialog>
#include <QList>
#include <consts.h>

namespace Ui {
class bonusResurssiDialogi;
}

class bonusResurssiDialogi : public QDialog
{
	Q_OBJECT

public:
	explicit bonusResurssiDialogi(Resurssi* resurssi, QList<Plantaasi*>& lista, QWidget *parent = 0);
	~bonusResurssiDialogi();

private slots:
	void on_buttonBox_accepted();

private:

	Resurssi* resurssi_;

	Ui::bonusResurssiDialogi *ui;
};

#endif // BONUSRESURSSIDIALOGI_H
