#include "nWindows.h"
#include <QtWidgets/QApplication>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

	nWindows w;
	w.show();
	return a.exec();
}
