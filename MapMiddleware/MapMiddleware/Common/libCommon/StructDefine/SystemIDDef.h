#ifndef SystemIDDef_H
#define SystemIDDef_H

#include <QString>

//软件逻辑ID

//雷侦分系统
#define		SYSTEM_RADAR					0x0001			//雷侦分系统编号
#define		SOFT_RS_SNUM_RADAR				0x000101		//雷达信号侦测显控软件短编号
#define		SOFT_RS_RADARSIGDETECT_1		0x00010101		//雷达信号侦测显控软件1
#define		SOFT_RS_RADARSIGDETECT_2		0x00010102		//雷达信号侦测显控软件2

//通侦分系统
#define		SYSTEM_COM						0x0002			//通侦分系统编号
#define		SOFT_CSR_SNUM_HOPFREQ			0x000201		//跳频信号侦测显控软件短编号
#define		SOFT_CSR_SNUM_GEN				0x000202		//常规信号侦测显控软件短编号
#define		SOFT_CSR_SUBMARINE				0x00020300		//浮标卫星信号侦收显控软件
#define		SOFT_CSR_SNUM_UNLINE			0x000204		//通侦离线分析软件短编号

//Link16分系统
#define		SYSTEM_LINK16					0x0003			//Link16分系统编号
#define		SOFT_TLR_LINK16SIGDETECT		0x00030100		//Link16信号侦测显控软件

//IFF / TACAN分系统
#define		SYSTEM_IFFTACAN					0x0004			//IFF / TACAN分系统编号
#define		SOFT_ITR_IFFTACANSIGDETECT		0x00040100		//IFF / TACAN信号侦测显控软件

//光侦分系统
#define		SYSTEM_LIGHT					0x0005			//光侦分系统编号
#define		SOFT_OF_LIGHTSIGDETECT			0x00050100		//光电侦察显控软件

//指控分系统
#define		SYSTEM_CMDCTRL						0x0006			//指控分系统编号
#define		SOFT_CIS_DATADISPATCH				0x00060100		//接入分发处理服务软件
#define		SOFT_CIS_SNUM_INTELLIGMANAGER		0x000602		//情报综合处理软件短编号
#define		SOFT_CIS_SITUATIONMANAGER			0x00060300		//态势情报处理软件
#define		SOFT_CIS_TASKMANAGER				0x00060400		//任务管理软件
#define		SOFT_CIS_SNUM_SITUATIONDISPLAY		0x000605		//态势显示软件短编号
#define		SOFT_CIS_SNUM_USERROLEMANGER		0x000606		//用户角色装配软件短编号
#define		SOFT_CIS_SNUM_INTERNAVDISPATCH		0x000607		//惯导接收分发软件短编号
#define		SOFT_CIS_LAUNCHWARNDISPATCH			0x00060800		//发射告警分发软件
#define		SOFT_CIS_AISDISPATCH				0x00060900		//AIS接收分发软件
#define		SOFT_CIS_VOICEIDENTIFY				0x00060A00		//语音识别软件

//任务通信分系统
#define		SYSTEM_TASKCOM						0x0007			//任务通信分系统编号
#define		SOFT_CS_TASKCOMMUNICATE				0x00070100		//任务通信显控软件
#define		SOFT_CS_SNUM_IMMEDICOMMUNICATE		0x000702		//即时通软件短编号

//分系统编号字符串
#define		STR_SYSTEM_RADAR		QString("0x0001")
#define		STR_SYSTEM_COM			QString("0x0002")
#define		STR_SYSTEM_LINK16		QString("0x0003")
#define		STR_SYSTEM_IFFTACAN		QString("0x0004")
#define		STR_SYSTEM_LIGHT		QString("0x0005")
#define		STR_SYSTEM_CMDCTRL		QString("0x0006")
#define		STR_SYSTEM_TASKCOM		QString("0x0007")

#endif // !SystemIDDef_H
