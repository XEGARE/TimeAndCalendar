#include "stdafx.h"
#include "CalendarWidget.h"

CalendarWidget::CalendarWidget(QWidget* parent)
	: QMainWindow(parent)
{
	QRect screen = QApplication::desktop()->screenGeometry();
	move(screen.width() * 0.7, screen.height() * 0.7);

	resize(screen.width() * 0.26, screen.height() * 0.18);

	dayWeek = new QLabel(this);
	dayWeek->setFixedSize(width(), height());
	dayWeek->setAlignment(Qt::AlignCenter);
	int id = QFontDatabase::addApplicationFont(":/TimeAndCalendar/Resources/Filmotype_LaCrosse.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont font(family, screen.height() * 0.1);
	dayWeek->setFont(font);
	QPalette sample_palette;
	sample_palette.setColor(QPalette::WindowText, QColor(255, 255, 255));
	dayWeek->setPalette(sample_palette);

	day = new QLabel(this);
	day->setFixedSize(width(), height());
	day->setGeometry(width() * 0.18, height() * 0.33, width(), height());
	int id2 = QFontDatabase::addApplicationFont(":/TimeAndCalendar/Resources/13501.ttf");
	QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
	QFont font2(family2, screen.height() * 0.015);
	day->setFont(font2);
	day->setPalette(sample_palette);
	day->setText("test");

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &CalendarWidget::CalendarUpdate);
	timer->start(1000);

	CalendarUpdate();

	setWindowTitle(tr("CalendarWidget"));

}

void CalendarWidget::CalendarUpdate()
{
	QString dayweek[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	QDate date = QDate::currentDate();
	dayWeek->setText(dayweek[date.dayOfWeek() - 1]);

	QString month[12] = { " January, "," February, "," March, "," April, "," May, "," June, "," July, "," August, "," September, "," October, "," November, "," December, " };

	QString daydate = QString::number(date.day()) + month[date.month() - 1].toUpper() + QString("2019");
	day->setText(daydate);
}