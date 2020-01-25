#pragma once

//信息类别定义

//信息类别长度
#define INFOCODELEN		2
//信息子类长度
#define SUBCODELEN		2
//16进制
#define HEXADECIMAL		16
//10进制
#define DECIMAL			10
//流水号长度
#define FLOWCODELEN		3

enum InfoCode
{
	Command_Control = 0xA1,			// 指挥控制信息
	System_Monitor = 0xA2,			// 系统监控信息
	Instrument_Sense = 0xA3,		// 手段侦测信息
	Intelligence_Dispose = 0xA4,	// 情报处理信息
	Cooperate_Scout = 0xA5,			// 协同侦察信息
	Reorganize_Guide = 0xA6,		// 整编引导信息
	Task_Comminucate = 0xA7,		// 任务通信信息
	System_Currency = 0xA8,			// 系统通用信息
	Resource_Manager = 0xA9,		// 资源管理信息
	Sound_Distinguish = 0xB0,		// 语音识别信息
	Situation_Mutual = 0xC0,		// 态势交互信息
	Collect_Manager = 0xD0,			// 采集管理信息
	Immediately_Mutual = 0xE0		// 即时通交互信息
};

//指挥控制信息_消息子类定义
enum CommandCtrl_SubInfoCode
{
	CommandNoticeDispatch = 0x01,			// 指挥文电通知分发
	CommandNoticeFeedback = 0x02,			// 指挥文电通知反馈
	TaskPlanNoticeDispatch = 0x03,			// 任务计划通知分发
	TaskPlanNoticeFeedback = 0x04,			// 任务计划通知反馈
	CCT_FileTransRequest = 0x05,			// 文件传输审批请求
	CCT_FileTransFeedback = 0x06,			// 文件传输审批反馈
	SupportIntelliNoticeDispatch = 0x07,	// 支援情报通知分发
	RRSPlanLeadNotice = 0x20,				// 雷侦任务计划引导通知
	CRSPlanLeadNotice = 0x30,				// 通侦任务计划引导通知
	IFFPlanLeadNotice = 0x40,				// IFF任务计划引导通知
	ReconAreaLeadNotice = 0x50,				// 侦察区域引导通知
	ArtificePlanExecFeedback = 0xF0,		// 手段任务计划执行反馈
	TaskExecuteStateDispatch = 0xF1,		// 任务执行状态分发
	CommandCtrlFeedback = 0xFF				// 指挥控制响应信息
};


//情报处理信息_消息子类定义
enum IntelliDispose_SubInfoCode
{
	IntelliMaterialReport = 0x01,			// 情报素材上报通知
	ColligIntelliReport = 0x02,				// 综合情报上报
	ColligIntelliFeedback = 0x03,			// 综合情报上报反馈
	ColligSituationDispatch = 0x04,			// 综合态势信息分发
	ExternPlatPosDispatch = 0x05,			// 外平台位置分发
	ExternPlatSituationDispatch = 0x06,		// 外平台态势分发
	ExternPlatSituationDiffReport = 0x07,	// 外平台态势判证差异报告
	DataLinkDataUpdate = 0x08,				// 数据链数据更新请求
	IntelliDisposeFeedback = 0xFF			// 情报处理响应信息
};

//协同侦察信息_消息子类定义
enum CooperateScout_SubInfoCode
{
	InnerCoopLead = 0x01,					// 内部协同引导
	InnerCoopFeedback = 0x02,				// 内部协同反馈
	ExterCoopTaskNotify = 0x03,				// 外部协同任务通知
	ExterCoopTaskNotifyFeedback = 0x04,		// 外部协同任务通知反馈
	ExterCoopSignalParam = 0x10,			// 外部协同信号参数
	ExterCoopSignalParamFeedback = 0x11,	// 外部协同信号参数反馈
	ExterCoopDirFindData = 0x12,			// 外部协同测向数据
	CooperateScoutFeedback = 0xFF			// 协同响应信息
};


//任务通信信息_消息子类定义
enum TaskComm_SubInfoCode
{
	CommandNotice = 0x01,					// 指挥文电通知
	FileTransNotice = 0x02,					// 文件传输通知
	TCT_FileTransFeedback = 0x03,			// 文件传输通知反馈
	FileTransState = 0x04,					// 文件传输状态
	ColligSituationTsData = 0x05,			// 综合态势传输数据
	AirplanePosTsData = 0x06,				// 载机位置传输数据
	SystemStateTsData = 0x07,				// 系统状态传输数据
	DataLinkRecvData = 0x08,				// 数据链接收数据
	DataLinkIDTable = 0x09,					// 数据链批号对照表
	DataLinkCoopTaskRequest = 0x0A,			// 数据链协同任务请求
	DataLinkCoopTaskFeedback = 0x0B,		// 数据链协同任务请求反馈
	DataLinkCoopSignalParam = 0x0C,			// 数据链协同信号参数
	DataLinkCoopSignalParamFeedback = 0x0D,	// 数据链协同信号参数反馈
	DataLinkCoopDirFindData = 0x0E,			// 数据链协同测向数据
	DataLinkMemberInfoDispatch = 0x0F,		// 数据链成员信息分发
	TaskCommFeedback = 0xFF					// 任务通信响应信息
};

//采集管理消息_消息子类定义
enum CollectManager_SubInfoCode
{
	TrainDataCollectNotice = 0x01,			// 训练数据采集通知
	CollectCtrlLeadCmd = 0x02,				// 采集控制引导指令
	CollectStateReport = 0x03,				// 采集状态上报
	CollectCtrlFeedback = 0xFF				// 采集控制响应信息
};

//数据链类型
 enum EDataLinkType
 {
	 DLT_Invalid = 0,	//无效
	 DLT_JIDS,			//JIDS
	 DLT_Link905,		//905链
	 DLT_SateCom		//卫通链路
 };

 //协同类型
 enum ECoopType
 {
	 CT_Invalid = 0,			//无效
	 CT_DoublePlanCoop,			//双机协同定位
	 CT_SkyLandCoop			//空地协同测向
 };

//协同控制类型
 enum ECoopCtrlType
 {
	 CCT_Invalid = 0,		//无效
	 CCT_Create,			//建立
	 CCT_Delete			//取消
 };

 //协同结果
 enum ECoopResultType
 {
	 CRT_Invalid = 0,		//无效
	 CRT_Agree,				//同意
	 CRT_Reject			//拒绝
 };

 //主从机角色
 enum EPlaneRoleType
 {
	 PRT_Invalid = 0,	//无效
	 PRT_Master,		//主机
	 PRT_Deputy		//从机
 };

 //协同状态
 enum ECoopStatusType
 {
	 CST_Invalid = 0,	//无效
	 CST_NoCoop,		//未协同
	 CST_Cooping		//协同中
 };

 //信号类型
 enum ESignalType
 {
	 T_Unknown = 0,//未知
	 RadarSig = 1,//雷达信号
	 SW = 2,//短波
	 SSW = 3,//超短波
	 MicroWave = 4,//微波
	 Report = 5,   //话报
	 MissileRemote = 6, //导弹遥测
	 HopFreq = 7,//跳频
	 SpreadFreq = 8,     //扩频
	 Link16 = 9,//Link16
	 TACAN = 10,//塔康
	 AIS = 11,//AIS
	 ACARS = 12,//ACARS
	 ADS_B = 13,//ADS-B
	 IFF = 14,//IFF 
	 IFF_US = 141,//美制IFF 
	 IFF_RUS = 142,//俄制IFF
	 IFFQue_US = 143,//美制IFF询问
	 IFFRes_US = 144,//美制IFF应答 
	 Gen_DataLink = 15,//常规数据链信号
	 Link11 = 151,//Link11数据链信号
	 Link4A = 152,//Link4A数据链信号
	 link14 = 153,//Link14数据链信号
	 Universal_Satellite = 16,//卫星信号		
	 Sea_Third_Satellite = 161,//海事三代卫星信号		
	 Sea_Forth_Satellite = 162,//海事四代卫星信号		
	 MaritimeIridium = 163,//铱星卫星信号		
	 NStar = 164,//NStar		
	 MSS = 165,//MSS		
	 Tactics_Star = 166,//战术星		
	 Orbcomm = 167,//Orbcomm
	 SubmarineBuoy = 17//反潜浮标信号
 };

