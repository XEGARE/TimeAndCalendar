#pragma once

#include <QtWidgets/QMainWindow>

class CalendarWidget : public QMainWindow
{
	Q_OBJECT

public:
	CalendarWidget(QWidget* parent = Q_NULLPTR);
	QLabel* dayWeek;
	QLabel* day;

private slots:
	void CalendarUpdate();
};