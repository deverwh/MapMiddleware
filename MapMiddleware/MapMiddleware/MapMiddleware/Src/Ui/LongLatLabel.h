#pragma once

#include <QWidget>
namespace Ui { class LongLatLabel; };

class LongLatLabel : public QWidget
{
	Q_OBJECT

public:
	LongLatLabel(QWidget *parent = Q_NULLPTR);
	~LongLatLabel();

	void set(qreal longitude, qreal latitude);

private:
	Ui::LongLatLabel *ui;
};
