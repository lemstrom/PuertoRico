#ifndef KAUPPIASDIALOGI_H
#define KAUPPIASDIALOGI_H

#include <QDialog>
#include <QList>
#include "./consts.h"

namespace Ui {
class KauppiasDialogi;
}

class KauppiasDialogi : public QDialog
{
	Q_OBJECT

public:
	explicit KauppiasDialogi(Resurssi* resurssi, QList<Resurssi>& lista, QWidget *parent = 0);
	~KauppiasDialogi();

private slots:
	void on_buttonBox_accepted();

	void on_buttonBox_rejected();

private:
	Resurssi* resurssi_;

	Ui::KauppiasDialogi *ui;
};

#endif // KAUPPIASDIALOGI_H
