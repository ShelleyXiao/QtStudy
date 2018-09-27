#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_nWindows.h"

class nWindows : public QMainWindow
{
	Q_OBJECT

public:
	nWindows(QWidget *parent = Q_NULLPTR);

private:
	Ui::nWindowsClass ui;
};
