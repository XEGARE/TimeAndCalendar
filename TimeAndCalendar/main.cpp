#include "stdafx.h"
#include "TimeWidget.h"
#include "CalendarWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TimeWidget TimeWidget;
	TimeWidget.setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	TimeWidget.setAttribute(Qt::WA_TranslucentBackground);
	TimeWidget.show();

	CalendarWidget CalendarWidget;
	CalendarWidget.setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	CalendarWidget.setAttribute(Qt::WA_TranslucentBackground);
	CalendarWidget.show();
	return a.exec();
}
