#ifndef KAPTEENIDIALOGI_H
#define KAPTEENIDIALOGI_H

#include <QDialog>
#include <consts.h>

namespace Ui {
class kapteenidialogi;
}

class kapteenidialogi : public QDialog
{
	Q_OBJECT

public:
	explicit kapteenidialogi(Resurssi* resurssi, QList<Resurssi>& lista, QWidget *parent = 0);
	~kapteenidialogi();

private slots:
	void on_buttonBox_accepted();

private:
	Resurssi* resurssi_;

	Ui::kapteenidialogi *ui;
};

#endif // KAPTEENIDIALOGI_H
