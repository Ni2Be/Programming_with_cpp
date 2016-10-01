#ifndef QTTRY_H
#define QTTRY_H

#include <QtWidgets/QMainWindow>
#include "ui_qttry.h"

class QTtry : public QMainWindow
{
	Q_OBJECT

public:
	QTtry(QWidget *parent = 0);
	~QTtry();

private:
	Ui::QTtryClass ui;
};

#endif // QTTRY_H
