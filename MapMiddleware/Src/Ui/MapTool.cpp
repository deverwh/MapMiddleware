#include "MapTool.h"
#include "ui_MapTool.h"
#include "AbstractMapHandle.h"
#include <QPushButton>

MapTool::MapTool(AbstractMapHandle *mapHandle /* = Q_NULLPTR */)
	: m_mapHandle(mapHandle)
{
	ui = new Ui::MapTool();
	ui->setupUi(this);
	this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	ui->arrowPushButton->setStyleSheet("border-image:url(:/images/btn_hover.png);");

	connect(m_mapHandle, &AbstractMapHandle::mapStateChanged, this, [&](MapHandleState::State state) 
	{
		switch (state)
		{
		case MapHandleState::Arrow:
			on_buttonGroup_buttonClicked(ui->arrowPushButton);
			break;
		case MapHandleState::Roaming:
			on_buttonGroup_buttonClicked(ui->roamingPushButton);
			break;
		case MapHandleState::ZoomIn:
			on_buttonGroup_buttonClicked(ui->zoomInPushButton);
			break;
		case MapHandleState::ZoonOut:
			on_buttonGroup_buttonClicked(ui->zoomOutPushButton);
			break;
		default:
			break;
		}
	});
}

MapTool::~MapTool()
{
	delete ui;
}


void MapTool::on_arrowPushButton_clicked()
{
	m_mapHandle->setMapState(MapHandleState::Arrow);
}

void MapTool::on_roamingPushButton_clicked()
{
	m_mapHandle->setMapState(MapHandleState::Roaming);
}

void MapTool::on_zoomInPushButton_clicked()
{
	m_mapHandle->setMapState(MapHandleState::ZoomIn);
}

void MapTool::on_zoomOutPushButton_clicked()
{
	m_mapHandle->setMapState(MapHandleState::ZoonOut);
}

void MapTool::on_buttonGroup_buttonClicked(QAbstractButton * button)
{
	button->setStyleSheet("border-image:url(:/images/btn_hover.png);");
	for (auto b : ui->buttonGroup->buttons())
	{
		if (b != button)
		{
			b->setStyleSheet("border-image:url(:/images/btn_normal.png);");
		}
	}
}

void MapTool::on_gridPushButton_clicked()
{
	if (m_isShowGrid)
	{
		m_mapHandle->setGridHidden(true);
		ui->gridPushButton->setStyleSheet("border-image:url(:/images/btn_normal.png);");
	}
	else
	{
		m_mapHandle->setGridHidden(false);
		ui->gridPushButton->setStyleSheet("border-image:url(:/images/btn_hover.png);");
	}
	m_isShowGrid = !m_isShowGrid;
}