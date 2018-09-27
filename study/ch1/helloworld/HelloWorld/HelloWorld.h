#pragma once

#include <QtWidgets/QWidget>
#include "ui_HelloWorld.h"

class HelloWorld : public QWidget
{
	Q_OBJECT

public:
	HelloWorld(QWidget *parent = Q_NULLPTR);

private:
	Ui::HelloWorldClass ui;
};
