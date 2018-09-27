#include "nWindows.h"
#include <qtextcodec.h>

nWindows::nWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	ui.pushButton->setText(codec->toUnicode("ÐÂ°´Å¥"));
}
