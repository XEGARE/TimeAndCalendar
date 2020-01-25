#include "stdafx.h"
#include "TimeWidget.h"

TimeWidget::TimeWidget(QWidget *parent)
	: QMainWindow(parent)
{
	resize(250, 250);

	QRect screen = QApplication::desktop()->screenGeometry();
	move(screen.width() * 0.03, screen.height() * 0.05);

	timeL = new QLabel(this);
	timeL->setFixedSize(width(), height());
	timeL->setAlignment(Qt::AlignCenter);
	int id = QFontDatabase::addApplicationFont(":/TimeAndCalendar/Resources/13501.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont font(family, width() * 0.18);
	timeL->setFont(font);
	QPalette sample_palette;
	sample_palette.setColor(QPalette::WindowText, QColor(77, 77, 77));
	timeL->setPalette(sample_palette);

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, QOverload<>::of(&TimeWidget::update));
	timer->start(100);

	TimeUpdate();

	setWindowTitle(tr("TimeWidget"));
}

void TimeWidget::TimeUpdate()
{
	QTime time = QTime::currentTime();
	QString text = time.toString("hh:mm");

	timeL->setText(text);
}

void TimeWidget::paintEvent(QPaintEvent*)
{
	QColor mainColor(204, 204, 204, 127);
	QColor secondColor(77, 77, 77);

	int side = qMin(width(), height());
	QTime time = QTime::currentTime();

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.translate(width() / 2, height() / 2);
	painter.scale(side / 200.0, side / 200.0);

	painter.setPen(QPen(mainColor, 5));
	painter.drawEllipse(-90, -90, 180, 180);

	painter.setPen(Qt::NoPen);

	painter.setBrush(mainColor);
	painter.drawEllipse(-75, -75, 150, 150);

	painter.setBrush(secondColor);

	painter.save();
	int sec = time.second()-1;
	painter.rotate(sec * 6.0);
	painter.drawEllipse(0, -(92 + height() / 50), width() * 0.06, height() * 0.06);
	painter.restore();

	painter.setPen(secondColor);

	TimeUpdate();
}
