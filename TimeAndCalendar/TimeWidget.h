#pragma once

#include <QtWidgets/QMainWindow>

class TimeWidget : public QMainWindow
{
	Q_OBJECT

public:
	TimeWidget(QWidget *parent = Q_NULLPTR);
	QLabel* timeL;

private slots:
	void TimeUpdate();

protected:
	void paintEvent(QPaintEvent* event) override;
};