#pragma once

#include <QWidget>
namespace Ui { class MapTool; };

class AbstractMapHandle;
class QAbstractButton;

class MapTool : public QWidget
{
	Q_OBJECT

public:
	MapTool(AbstractMapHandle *mapHandle);
	~MapTool();

private slots:
	void on_arrowPushButton_clicked();
	void on_roamingPushButton_clicked();
	void on_zoomInPushButton_clicked();
	void on_zoomOutPushButton_clicked();
	void on_buttonGroup_buttonClicked(QAbstractButton * button);
	void on_gridPushButton_clicked();

private:
	Ui::MapTool			*	ui;
	AbstractMapHandle	*	m_mapHandle		= nullptr;	// 地图实例
	bool					m_isShowGrid	= false;	// 是否显示经纬网格
};
