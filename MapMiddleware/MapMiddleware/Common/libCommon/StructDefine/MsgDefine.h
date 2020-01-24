////////////////////////////////////////////网络接口结构体定义//////////////////////////////
/*
*
*	waring:	需要在信号与槽中使用结构体作为参数时，请在结构体定义尾部加上Q_DECLARE_METATYPE(structName);		//注册自定义结构体  在信号与槽中使用
*/

#ifndef MSGDEFINE_H
#define MSGDEFINE_H

#include "InfoCode.h"
#include <QtCore>
#include <memory>

#pragma region 公共信息

using uint = unsigned int;		//使用无符号的int类型别名
using uchar = unsigned char;	//使用无符号的char类型别名
using ushort = unsigned short;	//使用无符号的short类型别名
using ullong = unsigned long long;	//使用无符号的long类型别名

#define BROADCAST_DESTLOGIC_ID 0

#define BROADCAST_SRCPLUGIN_ID 0xA001
#define BROADCAST_DESTPLUGIN_ID 0xA001

//结构体按照1字节对齐
#pragma pack(push, 1)

struct MsgHeader;
struct MsgEnd;

template<typename T>
struct Msg
{
	MsgHeader m_header;
	T m_data;
	QByteArray m_extData;
	MsgEnd m_end;
	Msg()
	{
		memset(&m_header, 0, sizeof(MsgHeader));
		memset(&m_data, 0, sizeof(T));
		m_extData.clear();
	};
	Msg(const MsgHeader &header, const T &data, const QByteArray &extData = QByteArray())
	{
		memset(&m_header, 0, sizeof(MsgHeader));
		memset(&m_data, 0, sizeof(T));
		m_extData.clear();
		m_header.DataFromBuf((char *)&header);
		m_data.DataFromBuf((char *)&data);
		m_extData = extData;
	}

	QByteArray toByteArray()
	{
		int frameLen = sizeof(MsgHeader)+sizeof(T)+m_extData.length() + sizeof(MsgEnd);
		QByteArray frame;
		// 帧头
		m_header.m_FrameLength = frameLen;
		frame.append((char *)&m_header, sizeof(m_header));
		// 数据
		frame.append((char *)&m_data, sizeof(m_data));
		// 扩展数据
		frame.append(m_extData);
		// 帧尾
		frame.append((char *)&m_end, sizeof(m_end));

		return frame;
	}

	QByteArray dataByteArray()
	{
		QByteArray frame;
		// 数据
		frame.append((char *)&m_data, sizeof(m_data));
		// 扩展数据
		frame.append(m_extData);
		return frame;
	}
};

/*定义消息头
*		其中ucMsgType(信息类别)定义如下：
* ucMsgType=0xA1;			指挥控制信息
* ucMsgType=0xA2;			系统监控信息
* ucMsgType=0xA3;			手段侦测信息
* ucMsgType=0xA4;			情报处理信息
* ucMsgType=0xA6;			整编引导信息
* ucMsgType=0xA7;			任务通信信息
* ucMsgType=0xA8;			系统通用信息
* ucMsgType=0xA9;			资源管理信息
* ucMsgType=0xB0;			语音识别信息
* ucMsgType=0xC0;			态势交互信息
* ucMsgType=0xD0;			即时通交互信息
*/
struct MsgHeader
{
	uint	m_FrameHead;				//帧头				4
	uint	m_SourceID;					//源逻辑ID			4
	uint	m_DstID;					//目的逻辑ID			4
	uint	m_FrameLength;				//帧长				4
	uchar	m_MsgType;					//信息类别			1
	uchar	m_MsgSubSystem;				//信息子类			1

	//构造函数
	MsgHeader()
	{
		memset(this, 0, sizeof(MsgHeader));
		this->m_FrameHead = 0x55555555;		//帧头为固定值
	}
	//重载构造函数
	MsgHeader(const uint &sourceID,const uint &dstID,const uint frameLength,
		const uchar &msgType, const uchar &msgSubSytem)
	{
		memset(this, 0, sizeof(MsgHeader));
		this->m_FrameHead = 0x55555555;		//帧头为固定值
		this->m_SourceID = sourceID;
		this->m_DstID = dstID;
		this->m_FrameLength = frameLength;
		this->m_MsgType = msgType;
		this->m_MsgSubSystem = msgSubSytem;
	}
	//拷贝数据到结构体中
	void DataFromBuf(char *buf)
	{
		memcpy(this, buf, sizeof(MsgHeader));
	}
};

//定义消息尾
struct MsgEnd 
{
	uint	m_FrameEnd;			//帧尾			4
	MsgEnd()
	{
		this->m_FrameEnd = 0xFFFFFFFF;			//使用固定值
	}
};

//消息主题由信息类别和信息子类组合而成，待定义

const static uint  commandNumberLength = 22;		//命令编号的字节长度 
const static uint  taskNameLength = 100;			//任务名称的字节长度
const static uint  taskNumberLength = 50;			//任务编号的字节长度
const static uint  dataBaseTableNameLength = 60;	//数据库表名的字节长度
const static uint  recordFlag = 32;					//记录标识的字节长度
const static uint  remarkLength = 100;				//备注字节长度
const static uint  fileName = 256;					//文件名称字节长度
const static uint  filePath = 256;					//文件路径字节长度

#pragma endregion

//////////////////////////////////Data数据字段定义////////////////////////////////////////

#pragma region 指挥控制信息

//指挥文电通知		主题标识（A7 - 01)
struct ZHNotify  		
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint    m_SendFlatNumber;								//发送平台编号	卫通链平台号，无效填0
	uint    m_ReceiveFlatNumber;							//接收平台编号	卫通链平台号，无效填0
	char	m_FilePath[256];								//文件路径		不能为空，必须有路径名，从0开始填充，其余填0
	char	m_FileName[256];								//文件名		从0开始填充，其余填0
	ZHNotify()
	{
		memset(this, 0, sizeof(ZHNotify));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ZHNotify));
	}
};
Q_DECLARE_METATYPE(ZHNotify);		//注册自定义结构体  在信号与槽中使用
//指挥文电通知分发		主题标识（A1-01)
struct ZHNotifyDistribute
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint	m_Time;										//时间		为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_TaskName[taskNameLength];						//任务名称  从第一个字节开始填充，其余填0，即指挥文电的标题。
	char   m_TaskNumber[taskNumberLength];					//任务编号	从第一个字节开始填充，其余填0	
	ushort  m_TimeOrder;									//时效等级  01（特急）、02（加急）、03（急）、04（平）
	ushort  m_MysterOrder;									//秘密等级  01（绝密）、02（机密）、03（秘密）、04（内部）、05（公开）
	ushort  m_AffixFlag;									//附件标志  0（无附件）、1（有附件）
	char	m_DataBaseTableName[dataBaseTableNameLength];	//数据库表名  数据表中指挥电文的库表名称
	char   m_RecordFlag[recordFlag];						//记录标识  填写数据表中指挥电文记录标识字段，从第一个字节开始填充，其余填0,通过记录获取正文内容和指挥附件信息。

	//构造函数 全部初始化为0
	ZHNotifyDistribute()
	{
		memset(this, 0, sizeof(ZHNotifyDistribute));
	}

	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ZHNotifyDistribute));
	}
};
Q_DECLARE_METATYPE(ZHNotifyDistribute);		//注册自定义结构体  在信号与槽中使用
//指挥文电通知反馈		主题标识（A1-02)
struct ZHNotifyFeedBack
{
	char	m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint    m_Time;											//时间		为相对1970年1月1日0时0分0秒的秒偏移量
	ushort  m_RoleNumber;									//角色编号  0（无效角色）、1（雷达信号主控侦测角色）、2（雷达信号副控侦测角色）
																		//3（通信信号侦测角色）、4（特殊信号侦查角色）、5（link16信号侦查角色）
																		//6(IFF和TACAN信号侦测角色）、7（光电侦查角色）、8（任务管理角色）、9（情报处理角色）
	ushort  m_FeedBackFlag;									//反馈状态  1（未阅）、2（已阅）、其他值无效，缺省值0 。

	//构造函数 全部初始化为0
	ZHNotifyFeedBack()
	{
		memset(this, 0, sizeof(ZHNotifyFeedBack));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ZHNotifyFeedBack));
	}
};
Q_DECLARE_METATYPE(ZHNotifyFeedBack);		//注册自定义结构体  在信号与槽中使用

//任务计划通知分发		主题标识（A1-03)
struct TaskPlanNotifyDistribute
{
	char	m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint    m_Time;											//时间		为相对1970年1月1日0时0分0秒的秒偏移量
	char	m_DataBaseTableName[dataBaseTableNameLength];	//数据库表名  数据表中任务计划的库表名称
	char	m_RecordFlag[recordFlag];						//记录标识  填写数据表中任务计划库表记录标识字段，从第一个字节开始填充，其余填0。

	//构造函数 全部初始化为0
	TaskPlanNotifyDistribute()
	{
		memset(this, 0, sizeof(TaskPlanNotifyDistribute));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(TaskPlanNotifyDistribute));
	}
};
Q_DECLARE_METATYPE(TaskPlanNotifyDistribute);		//注册自定义结构体  在信号与槽中使用
//任务计划通知反馈       主题标识（A1-04）
struct TaskPlanNofifyFeedBack
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint    m_Time;											//时间		为相对1970年1月1日0时0分0秒的秒偏移量
	ushort  m_RoleNumber;									//角色编号  0（无效角色）、1（雷达信号主控侦测角色）、2（雷达信号副控侦测角色）
	//3（通信信号侦测角色）、4（特殊信号侦查角色）、5（link16信号侦查角色）
	//6(IFF和TACAN信号侦测角色）、7（光电侦查角色）、8（任务管理角色）、9（情报处理角色）
	ushort  m_FeedBackFlag;									//反馈状态  1（未阅）、2（已阅）、其他值无效，缺省值0 。
	char	m_Remark[remarkLength];							//备注   需补充说明内容填写此字段，从第一个字节开始填充，其余填0
	//构造函数 全部初始化为0
	TaskPlanNofifyFeedBack()
	{
		memset(this, 0, sizeof(TaskPlanNofifyFeedBack));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(TaskPlanNofifyFeedBack));
	}
};
Q_DECLARE_METATYPE(TaskPlanNofifyFeedBack);		//注册自定义结构体  在信号与槽中使用
//手段任务计划执行反馈		主题标识（A1-F0)
struct ArtificePlanFeedBack
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	ushort	m_RoleNumber;									//角色编号
	char   m_TaskPlanID[32];								//任务计划ID	任务计划库表的标识
	ushort  m_ExecuteState;									//执行状态		0=无效；1 = 未执行(接收通知5秒后未执行则自动反馈此状态)；2 = 执行中；3 = 执行完成；4 = 执行暂停(人工暂停或自动暂停执行则自动上报此状态)；5 = 执行中止(人工中止则上报此状态)

	ArtificePlanFeedBack()
	{
		memset(this, 0, sizeof(ArtificePlanFeedBack));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ArtificePlanFeedBack));
	}
};
Q_DECLARE_METATYPE(ArtificePlanFeedBack);		//注册自定义结构体  在信号与槽中使用

//文件传输审批请求定义		主题标识（A1-05)
struct TransmitFileRequire
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint    m_Time;											//时间		  为相对1970年1月1日0时0分0秒的秒偏移量
	uint    m_ReceiveFlatNumber;							//接收平台号  填数据链网络成员平台号
	char   m_FileName[fileName];							//文件名称    传输文件名，含扩展名
	char   m_FilePath[filePath];							//文件路径
	char   m_Remark[remarkLength];							//备注        需补充说明，则填写此字段，从第一个字节开始填充，其余填0
	//构造函数 全部初始化为0
	TransmitFileRequire()
	{
		memset(this, 0, sizeof(TransmitFileRequire));
	}
	void DataFromBuf(const char* buf)
	{
		memcpy(this, buf, sizeof(TransmitFileRequire));
	}
};
Q_DECLARE_METATYPE(TransmitFileRequire);		//注册自定义结构体  在信号与槽中使用
Q_DECLARE_METATYPE(Msg<TransmitFileRequire>);

//文件传输审批反馈			主题标识（A1-06）
struct TransmitFileFeedBack
{
	enum PendType
	{
		Type_Invalid,	// 无效
		Type_Agree,		// 同意
		Type_Refuse,	// 拒绝
	};

	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint    m_Time;											//时间		  为相对1970年1月1日0时0分0秒的秒偏移量
	uint    m_ReceiveFlatNumber;							//接收平台号  填数据链网络成员平台号
	ushort  m_ExamineResult;								//审批结果    0（无效）、1（同意）、2（拒绝）
	char   m_Remark[remarkLength];							//备注        需补充说明，则填写此字段，从第一个字节开始填充，其余填0
	//构造函数 全部初始化为0
	TransmitFileFeedBack()
	{
		memset(this, 0, sizeof(TransmitFileFeedBack));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(TransmitFileFeedBack));
	}
};
Q_DECLARE_METATYPE(TransmitFileFeedBack);		//注册自定义结构体  在信号与槽中使用
Q_DECLARE_METATYPE(Msg<TransmitFileFeedBack>);		//注册自定义结构体  在信号与槽中使用

//支援情报通知分发(地面支援情报)			主题标识（A1-07)
struct SupportIntelligenceNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint    m_Time;											//时间		  为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_LeadObjectNumber[4];							//引导目标序号
	char   m_ObjectSrcNumber[22];							//目标（原）编号
	char   m_ObjectName[20];								//目标名称
	char   m_CountryArea[8];								//国家地区与组织
	char   m_Obtain;										//获取手段
	//构造函数 全部初始化为0
	SupportIntelligenceNotify()
	{
		memset(this, 0, sizeof(SupportIntelligenceNotify));
	}
};
Q_DECLARE_METATYPE(SupportIntelligenceNotify);		//注册自定义结构体  在信号与槽中使用

//单个目标位置点信息    属于支援情报的一部分
struct ObjectPoit
{
	uint	m_Time;				//位置时间	为相对1970年1月1日0时0分0秒的秒偏移量
	int     m_Longitude;		//经度		取值范围：[-180000000～180000000]，对应值域：[-180～180]；d)	单位/精度：0.000001°；无效值：181000000；说明：东经为正，西经为负。
	int     m_Latitude;			//纬度		取值范围：[-90000000～90000000]，对应值域：[-90～90]；单位 / 精度：0.000001°；无效值：91000000；说明：北纬为正，南纬为负。
	int     m_Height;			//高深度	取值范围/值域：[-3000,70000]；单位 / 精度： 1米；无效值： - 10000；说明：高度填写正值，深度填写负值。
	//默认初始化
	ObjectPoit()
	{
		this->m_Time = 0;
		this->m_Longitude = 181000000;
		this->m_Latitude = 91000000;
		this->m_Height = -10000;
	}
};

#pragma endregion

#pragma region 情报处理信息

//情报素材上报通知
struct CompreHensive_QB_ReportNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	ushort	m_SystemNumber;									//分系统编号
	uint	m_iTime;										//时间		 为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_DatabaseTableName[60];						//数据库表名 从第一个字节开始填充，其余填0
	char   m_RecordFlag[32];								//记录标识   数据表的标识字段数据，从第一个字节开始填充，其余填0
	CompreHensive_QB_ReportNotify()
	{
		memset(this, 0, sizeof(CompreHensive_QB_ReportNotify));
	}
};
Q_DECLARE_METATYPE(CompreHensive_QB_ReportNotify);		//注册自定义结构体  在信号与槽中使用

//综合情报上报
struct ComprehensiveIntelligenceReport
{
	char	m_CommandNumber[commandNumberLength];				//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号；
	uint	m_iTime;											//时间		 为相对1970年1月1日0时0分0秒的秒偏移量
	char	m_DatabaseTableName[60];							//数据库表名 从第一个字节开始填充，其余填0
	char	m_RecordFlag[32];									//记录标识   数据表的标识字段数据，从第一个字节开始填充，其余填0
	ComprehensiveIntelligenceReport()
	{
		memset(this, 0, sizeof(ComprehensiveIntelligenceReport));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ComprehensiveIntelligenceReport));
	}
};
Q_DECLARE_METATYPE(ComprehensiveIntelligenceReport);		//注册自定义结构体  在信号与槽中使用
Q_DECLARE_METATYPE(Msg<ComprehensiveIntelligenceReport>);

//综合情报上报反馈
struct CompreHensive_QB_ReportFeedBack
{
	enum Type
	{
		Type_Agree	= 0,	// 同意
		Type_Refuse = 1		// 拒绝
	};

	char	m_CommandNumber[commandNumberLength];			//命令编号	主体信息+“YYYYMMDDHHNNSS”+流水号；
	ushort	m_FeedBack;										//反馈结果	0（同意）、1（不同意）
	char	m_Remark[100];									//备注		需补充说明，则填写此字段，从第一个字节开始填充，其余填0
	CompreHensive_QB_ReportFeedBack()
	{
		memset(this, 0, sizeof(CompreHensive_QB_ReportFeedBack));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(CompreHensive_QB_ReportFeedBack));
	}
};
Q_DECLARE_METATYPE(CompreHensive_QB_ReportFeedBack);		//注册自定义结构体  在信号与槽中使用
Q_DECLARE_METATYPE(Msg<CompreHensive_QB_ReportFeedBack>);

#pragma endregion

//训练数据采集通知（地面训练系统数据采集）   主题标识（D0-01）
struct TrainDataCollectNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;											//时间		  为相对1970年1月1日0时0分0秒的秒偏移量
	ushort  m_SubSystemNumber;								//分系统编号
	ushort  m_CollectContrl;								//采集控制    0（无效）、1（启动）、2（结束）
	int     m_AreaLongitude;								//经度		取值范围：[-180000000～180000000]，对应值域：[-180～180]；d)	单位/精度：0.000001°；无效值：181000000；说明：东经为正，西经为负。
	int     m_AreaLatitude;									//纬度		取值范围：[-90000000～90000000]，对应值域：[-90～90]；单位 / 精度：0.000001°；无效值：91000000；说明：北纬为正，南纬为负。

	TrainDataCollectNotify()
	{
		memset(this, 0, sizeof(TrainDataCollectNotify));
	}
};

//采集控制响应信息  主题标识（D0 - FF）
struct stCollectCtrlFeedback
{
	char m_CommandNumber[commandNumberLength];			//命令编号   主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_FeedBackCode;								//响应故障码

	stCollectCtrlFeedback()
	{
		memset(this, 0, sizeof(stCollectCtrlFeedback));
	}

	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(stCollectCtrlFeedback));
	}
};

//训练数据采集通知启动参数  为训练数据采集通知中的采集控制部分
struct TrainDataNofigyStart
{
	uchar	m_ObjecCode;					//目标分类编码
	uint	m_SingalFeaturesExtend;			//信号特征扩展报文类型标识	按位表示，该位取值为1时表示具备此信号特征扩展报，该位为0时表示不存在此信号特征扩展报文。
	TrainDataNofigyStart()
	{
		memset(this, 0, sizeof(TrainDataNofigyStart));
	}
};
/*                               测向/定位扩展字段                 */
//超短波信号参数扩展
struct  Ultrashort_Parameter_Extend
{
	uchar	m_SingalType;			//信号类型
	ullong	m_Freq;					//频率		精度：1Hz 范围：[30000000, 3000000000]Hz
	ushort	m_ModelType;			//调制方式
	Ultrashort_Parameter_Extend()
	{
		memset(this, 0, sizeof(Ultrashort_Parameter_Extend));
	}
};
//卫星移动信号参数扩展
struct SatelliteMove_Parameter_Extend
{
	uchar	m_SingalType;				//信号类型
	ullong	m_UpFreq;					//上行频率	单位：Hz，精度：1Hz 范围:[100000000, 18000000000]Hz
	ullong	m_LowFreq;					//下行频率	单位：Hz，精度：1Hz 范围:[100000000, 18000000000]Hz

	SatelliteMove_Parameter_Extend()
	{
		memset(this, 0, sizeof(SatelliteMove_Parameter_Extend));
	}
};
//雷达信号参数扩展
struct Radar_Parameter_Extend
{
	uchar	m_RadioFreqCode;				//射频类型代码
	uint	m_RadioFreqStandard;			//射频标称值	取值范围：[40000～40000000] 无效：0；精度：0.001MHz；
											//	单位：MHz 对应值域：[400～40000]；射频取值1～6填写顺序如下，当射频取值超过6个时，任意挑选6个不同取值，当射频取值少于6个时，从射频取值1至射频取值6依次填写，剩余的射频取值填无效值 - 10000
	uchar	m_RepeatIntervalType;			//重复间隔类型
	uint	m_RepeatIntervalStandard;		//重复间隔标称值	单位/精度：1ns；无效值0; 取值范围：[3300～50000000]；
	uchar	m_PulseType;					//脉冲宽度类型代码
	uint	m_PulseStandard;				//脉冲宽度标称值		单位/精度：1ns；范围：[100～2000000]
	char	m_TypeName[20];					//类型名称
	Radar_Parameter_Extend()
	{
		memset(this, 0, sizeof(Radar_Parameter_Extend));
	}
};
//美制IFF信号参数扩展
struct AmericalIFF_Parameter_Extend
{
	uchar	m_ModelNumber;				//模式号代码
	char	m_ModelCode[10];			//模式码
	ushort	m_AirplanCode;				//飞机代码
	char	m_Address[6];				//地址码
	AmericalIFF_Parameter_Extend()
	{
		memset(this, 0, sizeof(AmericalIFF_Parameter_Extend));
	}
};
//俄制IFF信号参数扩展
struct RussiaIFF_Parameter_Extend
{
	uchar	m_ModelNumber;					//模式代号
	ushort	m_AirplanCode;					//飞机代码		解译BCD编码，(0001-7777),飞行中的飞机代码一旦确定就不会变化
	ullong	m_Freq;							//频率			单位：Hz，精度：1Hz 范围:[650000000, 2700000000]Hz
	uint	m_WorkModel;					//工作模式
	RussiaIFF_Parameter_Extend()
	{
		memset(this, 0, sizeof(RussiaIFF_Parameter_Extend));
	}
};
//导航信号参数扩展
struct Navigation_Parameter_Extend
{
	uchar	m_SingalType;				//信号类型
	uint	m_RadioFreq;				//射频频率		单位：Hz，精度：1Hz 范围:[962000000, 1213000000]Hz
	uchar	m_TACANModel;				//TACAN工作模式	范围：[0,255]见附录A的TACAN/DME工作模式
	char	m_Morsecode[4];				//莫尔斯码
	Navigation_Parameter_Extend()
	{
		memset(this, 0, sizeof(Navigation_Parameter_Extend));
	}
};
//数据链信号参数扩展
struct DataLink_Parameter_Extend
{
	uchar	m_SingalType;				//信号类型
	ullong	m_Freq;						//频率			单位：Hz，精度：1Hz 短波范围:[1500000, 30000000]Hz 超短波范围：[30000000, 3000000000]Hz
	ushort	m_NodeType;					//节点类型		-1=无效,1=网控站,2=前哨控制站;
	ushort	m_MyselfAddress;			//自身地址		本地PU码
	ushort	m_CallAddress;				//呼叫地址		呼叫PU码
	DataLink_Parameter_Extend()
	{
		memset(this, 0, sizeof(DataLink_Parameter_Extend));
	}
};
//跳频信号参数扩展
struct JumpFreq_Parameter_Extend
{
	ullong	m_StartFreq;					//起始频率		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ullong	m_StopFreq;						//终止频率		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ushort	m_JumpSpeed;					//跳速			单位：跳/秒；精度：0.1跳/秒；范围：[0,3000] 跳/秒
	JumpFreq_Parameter_Extend()
	{
		memset(this, 0, sizeof(JumpFreq_Parameter_Extend));
	}
};
//航空反潜浮标信号参数扩展
struct Aviation_Parameter_Extend
{
	ullong	m_UpFreq;				//上行频率		单位：Hz，精度：1Hz 上行136MHz～173.5MHz
	ullong	m_LowFreq;				//下行频率		单位：Hz，精度：1Hz 下行291.4MHz
	Aviation_Parameter_Extend()
	{
		memset(this, 0, sizeof(Aviation_Parameter_Extend));
	}
};
//微波信号参数扩展
struct  Microwave_Parameter_Extend
{
	uchar	m_SingalType;			//信号类型
	ullong	m_Freq;					//频率		单位：Hz，精度：1Hz 微波范围：[300000000, 300000000000]Hz 值域：[300MHz, 300GHz]
	ushort	m_ModelType;			//调制方式
	Microwave_Parameter_Extend()
	{
		memset(this, 0, sizeof(Microwave_Parameter_Extend));
	}
};

//雷侦任务计划引导通知		主题标识（A1-20)
struct RRSPlanLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_TaskPlanTitle[100];							//任务计划标题   从第一个字节开始填充，其余填0，即指挥文电的标题。
	char   m_TaskPlanID[32];								//任务计划ID	 任务计划库表的标识
	char   m_ReconObjectNumber[30];						//侦测目标内码
	int     m_AreaLongitude;								//经度		取值范围：[-180000000～180000000]，对应值域：[-180～180]；d)	单位/精度：0.000001°；无效值：181000000；说明：东经为正，西经为负。
	int     m_AreaLatitude;									//纬度		取值范围：[-90000000～90000000]，对应值域：[-90～90]；单位 / 精度：0.000001°；无效值：91000000；说明：北纬为正，南纬为负。
	ullong  m_StartFreq;									//普查起始频率		长度：8个字节；单位及精度： 1Hz；无效值：0
	ullong  m_StopFreq;										//普查终止频率		长度：8个字节；单位及精度： 1Hz；无效值：0 ；要求大于普查起始频率
	char   m_AntennaType[20];								//天线类型
	ullong  m_RadioFreqMin;									//射频频率最小值	长度：8个字节；单位及精度： 1Hz；无效值：0	
	ullong  m_RadioFreqMax;									//射频频率最大值	长度：8个字节；单位及精度： 1Hz；无效值：0 ；要求大于射频频率最小值
	uint	m_PRIMin;										//PRI最小值			取值范围和值域：[3300～50000000] 精度：1ns；单位：ns；无效：0；
	uint    m_PRIMax;										//PRI最大值			取值范围和值域：[3300～50000000] 精度：1ns；单位：ns；无效：0；
	uint    m_PulseWidthMin;								//脉宽最小值        范围及值域：[100～2000000]；精度：1ns；单位：ns；无效：0；
	uint    m_PulseWidthMax;								//脉宽最大值        范围及值域：[100～2000000]；精度：1ns；单位：ns；无效：0；

	RRSPlanLeadNotify()
	{
		memset(this, 0, sizeof(RRSPlanLeadNotify));
		this->m_AreaLongitude = 181000000;
		this->m_AreaLatitude = 91000000;
	}

};

//通侦任务计划引导通知      主题标识（A1-30)
struct CRSPlanLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_TaskPlanTitle[100];							//任务计划标题   从第一个字节开始填充，其余填0，即指挥文电的标题。
	char   m_TaskPlanID[32];								//任务计划ID	 任务计划库表的标识
	char   m_ReconObjectNumber[30];						//侦测目标内码
	int     m_AreaLongitude;								//经度		取值范围：[-180000000～180000000]，对应值域：[-180～180]；d)	单位/精度：0.000001°；无效值：181000000；说明：东经为正，西经为负。
	int     m_AreaLatitude;									//纬度		取值范围：[-90000000～90000000]，对应值域：[-90～90]；单位 / 精度：0.000001°；无效值：91000000；说明：北纬为正，南纬为负。
	ullong  m_StartFreq;									//普查起始频率		长度：8个字节；单位及精度： 1Hz；无效值：0
	ullong  m_StopFreq;										//普查终止频率		长度：8个字节；单位及精度： 1Hz；无效值：0 ；要求大于普查起始频率
	char   m_AntennaType[20];								//天线类型
	char   m_SingalSystem[64];								//信号体制		其它、跳频、扩频、并行多音、OFDM、PCMA、APCMA、VSAT、DVB-S、DVB-S2、跳扩频、模拟话、莫尔斯
	ullong  m_MidFreq;										//中心频率		长度：8个字节；单位及精度： 1Hz；无效值：0
	uint    m_SingalBandwith;								//信号带宽      范围:[0,800000000]Hz；单位/精度：1Hz；无效值为0；
	ushort  m_JumpSpeed;									//跳速			单位：跳/秒；精度：0.1跳/秒；范围：[0,3000] 跳/秒
	uchar   m_JumpFreq;										//跳频频率集个数  范围：[1,100]，必须大于1

	CRSPlanLeadNotify()
	{
		memset(this, 0, sizeof(CRSPlanLeadNotify));
	}
};

//IFF任务计划引导通知		主题标识（A1-40)
struct IFFPlanLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_TaskPlanTitle[100];							//任务计划标题   从第一个字节开始填充，其余填0，即指挥文电的标题。
	char   m_TaskPlanID[32];								//任务计划ID	 任务计划库表的标识
	char   m_ReconObjectNumber[30];						//侦测目标内码
	int     m_AreaLongitude;								//经度		取值范围：[-180000000～180000000]，对应值域：[-180～180]；d)	单位/精度：0.000001°；无效值：181000000；说明：东经为正，西经为负。
	int     m_AreaLatitude;									//纬度		取值范围：[-90000000～90000000]，对应值域：[-90～90]；单位 / 精度：0.000001°；无效值：91000000；说明：北纬为正，南纬为负。
	uchar   m_TechnicSystem;								//技术体制   0=未知； 1 = 北约体制；2 = 俄罗斯体制；3 = 塔康信号体制；255 = 自定义
	uchar   m_RadioFreq;									//射频频率个数  范围：[1,100]，必须大于1

	IFFPlanLeadNotify()
	{
		memset(this, 0, sizeof(IFFPlanLeadNotify));
	}
};

//侦测区域引导通知			主题标识（A1-50)
struct ReconAreaLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_TaskPlanTitle[100];							//任务计划标题	 从第一个字节开始填充，其余填0，即指挥文电的标题。
	char   m_TaskPlanID[32];								//任务计划ID	 任务计划库表的标识
	char   m_ReconObjectNumber[30];						//侦测目标内码
	int     m_AreaLongitude;								//经度		取值范围：[-180000000～180000000]，对应值域：[-180～180]；d)	单位/精度：0.000001°；无效值：181000000；说明：东经为正，西经为负。
	int     m_AreaLatitude;									//纬度		取值范围：[-90000000～90000000]，对应值域：[-90～90]；单位 / 精度：0.000001°；无效值：91000000；说明：北纬为正，南纬为负。
	char   m_ReconObject[100];								//侦测对象
	char   m_ReconArea[90];								//侦查区域
	ushort  m_ReconMode;									//帧照模式   1=红外；2=可见光

	ReconAreaLeadNotify()
	{
		memset(this, 0, sizeof(ReconAreaLeadNotify));
	}
};


//任务执行状态分发			主题标识（A1-F1)
struct TaskExecuteStateNotify
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	char   m_UnitNumber[10];								//单位编码
	char   m_FightFlag[20];								//架次标识
	char   m_FightName[60];								//架次名称
	char   m_TaskPlanFlag[20];								//任务计划标识
	char   m_FlatNumber[10];								//平台编号
	char   m_SkyWayFlag[20];								//航线标识
	char   m_ReconDirectionNumber[3];						//侦察方向编号

	TaskExecuteStateNotify()
	{
		memset(this, 0, sizeof(TaskExecuteStateNotify));
	}

};

//指挥控制响应消息			主题标识（A1-FF)
struct ZHContrlInfo_FeedBack
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_FeedBackCode;									//响应故障码

	ZHContrlInfo_FeedBack()
	{
		memset(this, 0, sizeof(ZHContrlInfo_FeedBack));
	}
};


#pragma region 协同侦察信息

// 内部协同引导
struct Inside_Coordination_Lead
{
	char m_CommandNumber[commandNumberLength];				//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	quint32 m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	quint8	m_SystemNumber;									//协同分系统编号
	quint8	m_Role;											//角色

	quint8	m_ObjectSystemNumber;							//被协同分系统编号
	quint8   m_ObjectRole;									//被协同角色
	quint16	m_Type;											//协同类型	  //BIT0：1：方位信息有效；0：方位信息无效；
																		  //BIT1：1：位置信息有效；0：位置信息无效；
																		  //BIT2：1：频率信息有效；0：频率信息无效；
																		  //BIT3：1：目标信息有效；0：目标信息无效；
																		  //BIT4：1：区域信息有限；0：区域信息无效；

	//目标信息
	quint8	m_ObjectType;									//目标种类
	char	m_ObjectName[90];								//目标名称
	char	m_ObjectModel[60];								//目标型号
	//位置信息
	qint32	m_Positon_Longitude;							//引导位置经度
	qint32		m_Position_Latitude;						//引导位置纬度
	//方位信息
	qint16	m_Azimuth;										//引导方位角	精度： 0.1°；无效值： - 10000；对应值域：[0～360]；备注：相对船头方向
	// 区域信息
	char	m_AreaName[90];									// 区域名称
	char	m_AreaNumber[32];								// 区域编号
	//频率信息
	quint8	m_SignalType;									//信号类型
	quint8	m_FreqCounts;									//频率个数		根据协同侦察信号类型确定详细的信号参数信息
	
	Inside_Coordination_Lead()
	{
		memset(this, 0, sizeof(Inside_Coordination_Lead));
	}
	void generateCommandNumber()
	{
		static int serialNumber = 0;
		auto commandNumber = QString("%1%2%3%4")
			.arg(Task_Comminucate, 2, 16, QChar('0'))
			.arg(CooperateScout_SubInfoCode::InnerCoopLead, 2, 16, QChar('0'))
			.arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"))
			.arg(++serialNumber, 3, 10, QChar('0'));
		commandNumber = commandNumber.toUpper();
		memcpy(this->m_CommandNumber, commandNumber.toLocal8Bit().data(), commandNumber.toLocal8Bit().length());
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Inside_Coordination_Lead));
	}
};
Q_DECLARE_METATYPE(Inside_Coordination_Lead);		//注册自定义结构体  在信号与槽中使用
Q_DECLARE_METATYPE(Msg<Inside_Coordination_Lead>);		//注册自定义结构体  在信号与槽中使用

//内部协同反馈
struct Inside_Coordination_FeedBack
{
	enum Type
	{
		ICFT_Unknown,		// 未知
		ICFT_UnExec,		// 未执行
		ICFT_Execing,		// 执行中
		ICFT_Execed,		// 执行完成
		ICFT_ExecPause,		// 执行暂停
		ICFT_ExecLetup,		// 执行中止
	};

	char m_CommandNumber[commandNumberLength];				//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	quint32 m_Time;											//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	quint8	m_SystemNumber;									//反馈的分系统编号
	quint8	m_Role;											//反馈的角色
	char	m_RecordFlag[20];								//反馈记录标识	数据库中记录的相应情报请求反馈信息的唯一标识
	quint8	m_CoordinationFeedBack;							//协同反馈情况	0=无效；1 = 未执行(接收通知5秒后未执行则自动反馈此状态)；2 = 执行中； 3 = 执行完成；4 = 执行暂停(人工暂停或自动暂停执行则自动上报此状态)；5 = 执行中止(人工中止则上报此状态)；
	quint16	m_TextLength;									//说明正文长度	0时，无说明正文字段，范围0-2000

	Inside_Coordination_FeedBack()
	{
		memset(this, 0, sizeof(Inside_Coordination_FeedBack));
	}
	void generateCommandNumber()
	{
		static int serialNumber = 0;
		auto commandNumber = QString("%1%2%3%4")
			.arg(Task_Comminucate, 2, 16, QChar('0'))
			.arg(CooperateScout_SubInfoCode::InnerCoopFeedback, 2, 16, QChar('0'))
			.arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"))
			.arg(++serialNumber, 3, 10, QChar('0'));
		commandNumber = commandNumber.toUpper();
		memcpy(this->m_CommandNumber, commandNumber.toLocal8Bit().data(), commandNumber.toLocal8Bit().length());
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Inside_Coordination_FeedBack));
	}
};
Q_DECLARE_METATYPE(Inside_Coordination_FeedBack);		//注册自定义结构体  在信号与槽中使用
Q_DECLARE_METATYPE(Msg<Inside_Coordination_FeedBack>);		//注册自定义结构体  在信号与槽中使用

//外部协同任务通知
struct Out_Coop_Notify
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;										//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	uchar	m_CoordinationType;							//协同类型		0-无效；1 - 双机协同定位(飞机主导协同，主机定位，双机在通距内)；
														//				2 - 空地协同测向(地面主导协同和定位，双机存在共视区)；
	
	Out_Coop_Notify()
	{
		memset(this, 0, sizeof(Out_Coop_Notify));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Out_Coop_Notify));
	}
};

//外部协同任务通知反馈
struct Out_Coop_Notify_Feedback
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint    m_Time;										//时间		     为相对1970年1月1日0时0分0秒的秒偏移量
	uchar	m_CoordinationType;							//协同类型		0-无效；1 - 双机协同定位(飞机主导协同，主机定位，双机在通距内)；
														//				2 - 空地协同测向(地面主导协同和定位，双机存在共视区)；
	ushort  m_ExecuteState;								//执行状态		0=无效；1 = 未执行(接收通知5秒后未执行则自动反馈此状态)；2 = 执行中；3 = 执行完成；4 = 执行暂停(人工暂停或自动暂停执行则自动上报此状态)；5 = 执行中止(人工中止则上报此状态)

	Out_Coop_Notify_Feedback()
	{
		memset(this, 0, sizeof(Out_Coop_Notify_Feedback));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Out_Coop_Notify_Feedback));
	}
};

Q_DECLARE_METATYPE(Out_Coop_Notify_Feedback);

//外部协同信号参数
struct Outside_Coordination_SingalParameter
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//任务通信传输内容
	uint	m_SendPlatformNumber;							//发送平台编号	JIDS、905链、卫通链平台号，无效填0
	uint	m_ReceivePlatformNumber;						//接收平台编号  
	uint	m_Coordination_StartTime;						//协同开始时间
	uchar	m_Coordination_KeepTime;						//协同驻留时长	单位/精度：1s，范围：[0,1000],为0则无时间限制
	uchar	m_ReconType;									//侦测手段类型
	uchar	m_Location_Contrl;								//定位控制0=无效；1 = 开始协同侦察；2 = 停止协同侦察；
	uchar	m_Coordination_Type;							//协同类型		0-无效；1 - 双机协同定位(飞机主导协同)；2 - 双机协同测向(地面主导协同)；
	int		m_ReconAreaLongitude;							//侦察区域经度
	int     m_ReconAreaLatitude;							//侦察区域纬度
	uchar	m_SingalParameterFlag;							//信号参数标志	0=无效; 1 = 无信号参数(适用于停止)；2 = 有信号参数(适合于启动)；
	uchar	m_CoopSigNum;									//协同信号个数N	N小于等于3

	Outside_Coordination_SingalParameter()
	{
		memset(this, 0, sizeof(Outside_Coordination_SingalParameter));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Outside_Coordination_SingalParameter));
	}

};
//单个协同信号参数  (为外部协同信号参数的子项)
struct Coordination_SingalParameter
{
	uchar	m_SingalType;								//信号类型
	ushort	m_ParameterNumber;							//协同参数编号	发起方填充的发起方系统分配的信号/辐射源编号或者单独编号(地面系统使用)，
	//必须保证其唯一性，按照信号类型分别编号，从1开始，到最大后从1循环编号
	ushort	m_ParameterFlag;							//信号参数标识	按位表示，该位取值为1时表示具备此信号协同侦察信号参数，该位为0时表示不存在此信号特征扩展报文。
	Coordination_SingalParameter()
	{
		memset(this, 0, sizeof(Coordination_SingalParameter));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Coordination_SingalParameter));
	}
};
//外部协同信号参数反馈
struct Outside_Coordination_SingalParameterFeedBack
{
	char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//任务通信传输内容
	uint	m_SendPlatformNumber;						//发送平台编号	综合链平台ID
	uint	m_ReceivePlatformNumber;					//接收平台编号
	uint	m_CoordinationStartTime;					//协同开始时间
	uchar	m_ReconType;								//侦察手段类型
	uchar	m_SingalType;								//信号类型
	uint	m_CoordinationParameterCode;				//协同参数编号	与协同请求中的协同编号一致或命令的参数编号一致，反馈类型为0时填0；
	uchar	m_LocationContrlFlag;						//定位控制状态	0=无效；1 = 开始协同侦察；2 = 停止协同侦察；
	uchar	m_CoordinationFBType;						//协同反馈类型	0=无效；1 = 协同成功；2 = 协同失败；255 = 参数错误；
	char	m_Text[30];									//正文			根据正文长度进行确定

	Outside_Coordination_SingalParameterFeedBack()
	{
		memset(this, 0, sizeof(Outside_Coordination_SingalParameterFeedBack));
	}

};
//外部协同侧向数据
struct Outside_Coordination_TestData
{
	char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//任务通信传输内容
	uint	m_SendPlatformNumber;						//发送平台编号	JIDS、905链、卫通链平台号，无效填0
	uint	m_ReceivePlatformNumber;					//接收平台编号
	uchar	m_SystemNumber;								//分系统编号
	uchar	m_SingalType;								//信号类型
	uint	m_CoordinationParameterCode;				//协同参数编号
	ullong	m_TestTime;									//测向时间
	ushort	m_IndicationDegree;							//示向度		单位：°无效值：3610 对应值域：[0～360] 备注：此方位以正北为零度，顺时针方向为正
	int		m_Longitude;								//平台经度		取值范围：[-180000000～180000000]，对应值域：[-180～180]；d)	单位/精度：0.000001°；无效值：181000000；说明：东经为正，西经为负。
	int		m_Latitude;									//平台纬度		取值范围：[-90000000～90000000]，对应值域：[-90～90]；单位 / 精度：0.000001°；无效值：91000000；说明：北纬为正，南纬为负。
	int		m_High;										//平台高度
	uchar	m_ParameterSign;							//信号参数标志	0=无效 1 = 无信号参数(适用于双机协同定位)；2 = 有信号参数(适用于空空 / 空地协同测向，向地面上报测向数据时)；
	ushort	m_ParameterFlag;							//信号参数标识
	Outside_Coordination_TestData()
	{
		memset(this, 0, sizeof(Outside_Coordination_TestData));
		this->m_IndicationDegree = 3610;
		this->m_Longitude = 181000000;
		this->m_Latitude = 91000000;
	}
};
//协同响应信息
struct Coordination_FeedBack
{
	char m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	uint	m_FeedBackCode;									//响应故障码
	Coordination_FeedBack()
	{
		memset(this, 0, sizeof(Coordination_FeedBack));
	}
};
#pragma endregion

#pragma region 任务通信信息
// 文件传输通知
struct FileTransmitNotice
{
	enum ControlType
	{
		Start = 1,
		Stop = 2,
	};

	char	m_CommandNumber[commandNumberLength];			//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	quint16	m_subSystemNumber;								// 发送分系统编号
	quint32	m_sendPlatNumber;								// 发送平台编号
	quint32 m_receivePlatNumber;							// 接收平台编号
	quint8	m_controlType;									// 控制启停, 0=无效；	1 = 开始传输；2 = 停止传输；
	char	m_filePath[256];								// 文件路径，FTP路径
	char	m_fileName[256];								// 传输文件名
	FileTransmitNotice()
	{
		memset(this, 0, sizeof(FileTransmitNotice));
		generateCommandNumber();
	}
	void generateCommandNumber()
	{
		static int serialNumber = 0;
		auto commandNumber = QString("%1%2%3%4")
			.arg(Task_Comminucate, 2, 16, QChar('0'))
			.arg(TaskComm_SubInfoCode::FileTransNotice, 2, 16, QChar('0'))
			.arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"))
			.arg(++serialNumber, 3, 10, QChar('0'));
		commandNumber = commandNumber.toUpper();
		memcpy(this->m_CommandNumber, commandNumber.toLocal8Bit().data(), commandNumber.toLocal8Bit().length());
	}
};


// 文件传输通知反馈
struct FileTransmitNoticeFeedback
{
	enum FeedbackState
	{
		Unvaild		= 0,	// 无效
		NotExecute	= 1,	// 未执行
		Executing	= 2,	// 执行中
		Finished	= 3,	// 执行完成
		Pause		= 4,	// 执行暂停
		Stop		= 5,	// 执行终止
	};

	char	m_CommandNumber[commandNumberLength];			// 命令编号，主体信息+“YYYYMMDDHHNNSS”+流水号，填文件传输通知的命令编号
	quint32	m_time;											// 时间
	quint16	m_subSystemNumber;								// 发送平台编号
	quint16 m_feedbackState;								// 接收平台编号
	FileTransmitNoticeFeedback()
	{
		memset(this, 0, sizeof(FileTransmitNoticeFeedback));
	}

	void DataFromBuf(const char* buf)
	{
		memcpy(this, buf, sizeof(FileTransmitNoticeFeedback));
	}
};
Q_DECLARE_METATYPE(FileTransmitNoticeFeedback)
Q_DECLARE_METATYPE(Msg<FileTransmitNoticeFeedback>)

// 文件传输状态
struct FileTransmitState
{
	enum State
	{
		Unvaild		= 0,	// 无效
		Transmit	= 1,	// 传输状态
		Wait		= 2,	// 等待状态
		Stop		= 3,	// 停止状态
		Finished	= 4,	// 完成状态
		Fault		= 5,	// 故障状态
	};

	char	m_CommandNumber[commandNumberLength];	// 命令编号，主体信息+“YYYYMMDDHHNNSS”+流水号，填文件传输通知的命令编号
	char	m_fileName[256];						// 文件名称，即关联名称
	quint8	m_state;								// 传输状态  0-无效；1-传输状态；2-等待状态；3-停止状态；4-完成状态；5-故障状态；其他值无效
	quint32 m_progress;								// 传输进度  [0,10000],单位%，精度：0.01% 范围:[0, 100], 其余值无效，缺省为0
	FileTransmitState()
	{
		memset(this, 0, sizeof(FileTransmitState));
	}

	void DataFromBuf(const char* buf)
	{
		memcpy(this, buf, sizeof(FileTransmitState));
	}
};
Q_DECLARE_METATYPE(FileTransmitState)
Q_DECLARE_METATYPE(Msg<FileTransmitState>)

//数据链数据头
struct DataLink_Header
{
	char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	ushort	m_DataLinkType;								//数据链类型	0=无效；1=JIDS链；2=905链；3=卫通链路

	DataLink_Header()
	{
		memset(this, 0, sizeof(DataLink_Header));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Header));
	}
};

//数据链协同任务请求
struct DataLink_TaskRequest
{
	//char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//ushort	m_DataLinkType;								//数据链类型	0=无效；1=JIDS链；2=905链；3=卫通链路
	////任务通信传输内容
	////4908报头！！！   暂时使用char占据位置
	//char	m_Report[46];

	uint	m_SendPlatform;								//发送平台成员	填数据链成员信息分发中的网络成员平台号
	uint	m_ReceivePlatform;							//接收平台成员
	uchar	m_CoordinationType;							//协同类型		0-无效；1 - 双机协同定位(飞机主导协同，主机定位，双机在通距内)；
	//				2 - 空地协同测向(地面主导协同和定位，双机存在共视区)；
	uchar	m_CoordinationContrl;						//协同控制		0-无效；1-建立；2-取消；
	ushort	m_RequestNumber;							//请求流水号	从1开始编号，[1,65535],超过65535则重1继续编号，由空中或地面任务管理软件负责产生和维护，
	//				按照协同类型分别编号，按天重新编号
	uchar	m_TextLength;								//正文长度		协同申请正文的长度描述，[0,60],为0时无“协同申请正文”字段
	//uchar	m_Text[N];									//协同请求正文
	DataLink_TaskRequest()
	{
		memset(this, 0, sizeof(DataLink_TaskRequest));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_TaskRequest));
	}
};
//数据链协同任务请求反馈
struct DataLink_TaskRequest_FeedBack
{
	//char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//ushort	m_DataLinkType;								//数据链类型	0=无效；1=JIDS链；2=905链；3=卫通链路
	////任务通信传输内容
	////4908报头！！！   暂时使用char占据位置
	//char	m_Report[46];

	uint	m_SendPlatform;						//发送平台编号	填数据链成员信息分发中的网络成员平台号
	uint	m_ReceivePlatform;					//接收平台编号
	ushort	m_RequestNumber;							//请求流水号	与协同请求中的协同编号一致，反馈类型为0时填0；
	uchar	m_CoordinationResult;						//协同结果		0-无效；1-同意；2-拒绝； 
	uchar	m_TextLength;								//正文长度		反馈正文正文的长度描述，[0,60],为0时无“反馈正文”字段
	//uchar	m_Text[N];									//正文
	DataLink_TaskRequest_FeedBack()
	{
		memset(this, 0, sizeof(DataLink_TaskRequest_FeedBack));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_TaskRequest_FeedBack));
	}
};
//数据链协同信号参数
struct DataLink_Parameter
{
	//char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//ushort	m_DataLinkType;								//数据链类型	0=无效；1=JIDS链；2=905链；3=卫通链路
	////任务通信传输内容
	////4908报头！！！   暂时使用char占据位置
	//char	m_Report[46];

	uint	m_SendPlatformNumber;						//发送平台编号	JIDS、905链，无效填0
	uint	m_ReceivePlatformNumber;					//接收平台编号	JIDS、905链，无效填0
	uchar	m_ReconType;								//侦察手段类型
	uchar	m_SingalType;								//信号类型
	uint	m_CoordinationParameter;					//协同参数编号	发起方填充的发起方系统分配的信号/辐射源编号或者单独编号(地面系统使用)，
														//				必须保证其唯一性，按照信号类型分别编号，从1开始，到最大后从1循环编号
	uchar	m_LocationContrl;							//定位控制		0=无效；1 = 开始协同侦察；2 = 停止协同侦察；
	uchar	m_CoordinationType;							//协同类型		0-无效；1 - 双机协同定位(飞机主导协同)；2 - 双机协同测向(地面主导协同)；
	int		m_ReconLongitude;							//侦察区域经度
	int		m_ReconLatitude;							//侦察区域纬度	
	uchar	m_SingalParaFlag;							//信号参数标志	0=无效 1 = 有信号参数(适用于开始协同侦察)；2 = 无信号参数(适用于停止协同侦察)；
	uchar	m_Save;										//保留字段
	DataLink_Parameter()
	{
		memset(this, 0, sizeof(DataLink_Parameter));
	}
};
//数据链协同信号参数反馈
struct DataLink_Parameter_FeedBack
{
	//char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//ushort	m_DataLinkType;								//数据链类型	0=无效；1=JIDS链；2=905链；3=卫通链路
	////任务通信传输内容
	////4908报头！！！   暂时使用char占据位置
	//char	m_Report[46];

	uint	m_SendPlatformNumber;						//发送平台编号	JIDS、905链，无效填0
	uint	m_ReceivePlatformNumber;					//接收平台编号	JIDS、905链，无效填0
	uchar	m_ReconType;								//侦察手段类型
	uchar	m_SingalType;								//信号类型
	uint	m_CoordinationParameter;					//协同参数编号	与协同请求中的协同编号一致或命令的参数编号一致，反馈类型为0时填0；
	
	uchar	m_LocationContrl;							//定位控制状态	0=无效；1 = 开始协同侦察；2 = 停止协同侦察；
	uchar	m_CoordinationFBType;						//协同反馈类型	0=无效；1 = 协同成功；2 = 协同失败；255 = 参数错误；
	uchar	m_TextLength;								//正文长度
	//uchar m_Text[N];									//正文
	DataLink_Parameter_FeedBack()
	{
		memset(this, 0, sizeof(DataLink_Parameter_FeedBack));
	}
};
//数据链协同测向数据
struct DataLink_DirFindData
{
	//char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	//ushort	m_DataLinkType;								//数据链类型	0=无效；1=JIDS链；2=905链；3=卫通链路
	////任务通信传输内容
	////4908报头！！！   
	//char	m_Report[46];	//暂时使用char占据位置

	uint	m_SendPlatformNumber;						//发送平台编号	JIDS、905链，无效填0
	uint	m_ReceivePlatformNumber;					//接收平台编号	JIDS、905链，无效填0
	ushort	m_IntentionID;								//目的逻辑ID	消息接收的逻辑ID(空空/空地协同测向时，此字段无效)
	uchar	m_SystemNumber;								//分系统编号
	uchar	m_SingalType;								//信号类型
	uint	m_CoordinationNumber;						//协同参数编号	填充协同命令中的参数编号
	ullong	m_TestTime;									//测向时间
	ushort	m_IndecationDegree;							//示向度		取值范围：[0～3600] 单位：° 无效值：3610
														//				对应值域：[0～360] 备注：此方位以正北为零度，顺时针方向为正
	uchar	m_IndecationBelive;							//示向度置信度	[0,100]%
	int		m_PlatformLongitude;						//平台经度
	int		m_PlatformLatitude;							//平台纬度
	int		m_PlatformHigh;								//平台高度
	uchar	m_SingalParameterSign;						//信号参数标识	0=无效 1 = 无信号参数(适用于双机协同定位)；
														//				2 = 有信号参数(适用于空空 / 空地协同测向，向地面上报测向数据时)；
	ushort	m_SingalParameterFlag;						//信号参数标识
	DataLink_DirFindData()
	{
		memset(this, 0, sizeof(DataLink_DirFindData));
	}
};
//数据链成员信息分发
struct DataLink_Distribute
{
	char m_CommandNumber[commandNumberLength];		//命令编号		 主体信息+“YYYYMMDDHHNNSS”+流水号;
	ushort	m_Counts;									//数据链成员个数
	//数据链成员信息

	DataLink_Distribute()
	{
		memset(this, 0, sizeof(DataLink_Distribute));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Distribute));
	}
};
//单个数据链成员信息（用在数据链成员信息分发中）
struct DataLink_Single
{
	char	m_Name[recordFlag];							//数据链成员名称
	ushort	m_Type;							//数据链成员类型	0=无效；1=JIDS链；2=905链；3=卫通链路
	uchar	m_PlatformFlag;					//平台标识			0-本平台；1-其他平台
	uint	m_PlatformNumber;				//数据链平台号		JIDS、905链、卫通链平台号，无效填0
	DataLink_Single()
	{
		memset(this, 0, sizeof(DataLink_Single));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Distribute));
	}
};
#pragma endregion 

/*								协同侦察拓展字段								*/
//超短波信号协同侦察信号参数
struct Ultrashort_Coordination_Extend
{
	ullong	m_Freq;					//频率		精度：1Hz 范围：[30000000, 3000000000]Hz
	ushort	m_ModelType;			//调制方式
	uint	m_SymbolSpeed;			//符号速率	单位SPS
	Ultrashort_Coordination_Extend()
	{
		memset(this, 0, sizeof(Ultrashort_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Ultrashort_Coordination_Extend));
	}
};
//卫星信号协同侦察信号参数
struct Satellite_Coordination_Extend
{
	ullong	m_UpFreq;					//上行频率	取值范围：[30000000～3000000000]；单位：Hz；精度：1 Hz；无效值：0。
	ullong	m_ModelSpeed;				//调制速率	单位：波特
	ushort	m_ModelType;				//调制方式
	Satellite_Coordination_Extend()
	{
		memset(this, 0, sizeof(Satellite_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Satellite_Coordination_Extend));
	}
};
//雷达信号协同侦察信号参数
struct Radar_Coordination_Extend
{
	uchar	m_RadioFreqType;					//射频类型
	int		m_RadioFreqStandard;				//射频标称值	单位/精度：1kHz；范围：[500000,40000000]kHz，无效值0
	int		m_RadioFreqMin;						//射频最小值
	int		m_RadioFreqMax;						//射频最大值
	int		m_RadioFreqValue1;					//射频取值1
	int		m_RadioFreqValue2;					//射频取值2
	int		m_RadioFreqValue3;					//射频取值3
	
	ushort	m_RepeatIntervalType;				//重复间隔类型
	uint	m_RepeatIntervalStandard;			//重复间隔标称值	单位/精度：1ns；无效值0; 取值范围：[660～10000000]；
	uint	m_RepeatIntervalUp;					//重复间隔上限值	
	uint	m_RepeatIntervalLow;				//重复间隔下限值
	uint	m_RepeatIntervalValue1;				//重复间隔取值1
	uint	m_RepeatIntervalValue2;				//重复间隔取值2
	uint	m_RepeatIntervalValue3;				//重复间隔取值3

	ushort	m_PulseType;						//脉宽类型
	uint	m_PulseStandard;					//脉宽标称值		单位/精度：1ns；范围：[20～400000]
	uint	m_PulseUp;							//脉宽上限值
	uint	m_PulseLow;							//脉宽下限值
	Radar_Coordination_Extend()
	{
		memset(this, 0, sizeof(Radar_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Radar_Coordination_Extend));
	}
};
//美制IFF信号协同侦察信号参数
struct AmericalIFF_Coordination_Extend
{
	uchar	m_ModelNumber;					//模式代号
	uint	m_AirplanAddress;				//飞机地址	应答模式的解译BCD编码，(0001-7777),飞行中的飞机代码一旦确定就不会变化 作为询问及应答模式S的关联参数
	uint	m_CodeInfo;						//编码信息	无效值：0xFFFF FFFF 作为普通应答的关联参数
	char	m_Save[6];						//保留		保留参数
	AmericalIFF_Coordination_Extend()
	{
		memset(this, 0, sizeof(AmericalIFF_Coordination_Extend));
		this->m_CodeInfo = 0xFFFF;
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(AmericalIFF_Coordination_Extend));
	}
};
//俄制IFF信号协同侦察信号参数
struct RussiaIFF_Coordination_Extend
{
	uchar	m_ModelNumber;				//模式代号
	uint	m_Airplancode;				//飞机代码	解译BCD编码，(0001-7777),飞行中的飞机代码一旦确定就不会变化 作为俄制IFF应答信号的关联参数
	ullong	m_Freq;						//频率	单位：Hz，精度：1Hz 范围:[650000000, 2700000000]Hz
	ushort	m_Save;						//保留字段	保留字段，全0
	RussiaIFF_Coordination_Extend()
	{
		memset(this, 0, sizeof(RussiaIFF_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(RussiaIFF_Coordination_Extend));
	}
};
//导航信号协同侦察信号参数
struct Navigation_Coordination_Extend
{
	ullong	m_RadioFreq;					//射频频率	单位：Hz，精度：1Hz 范围:[962000000, 1213000000]Hz
	uchar	m_TACANModel;					//TACAN工作模式		范围：[0,255]见附录A的TACAN/DME工作模式
	char	m_DistinguishCode[30];				//台站识别码
	Navigation_Coordination_Extend()
	{
		memset(this, 0, sizeof(Navigation_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Navigation_Coordination_Extend));
	}
};
//常规数据链信号协同侦察信号参数
struct DataLink_Coordination_Extend
{
	ullong	m_Freq;						//频率	单位：Hz，精度：1Hz 短波范围:[1500000, 30000000]Hz 超短波范围：[30000000, 3000000000]Hz
	ushort	m_ModelType;				//调制方式
	ushort	m_Address;					//自身地址	本地PU码
	DataLink_Coordination_Extend()
	{
		memset(this, 0, sizeof(DataLink_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Coordination_Extend));
	}
};
//跳频信号协同侦察信号参数
struct JumpFreq_Coordination_Extend
{
	ushort	m_NetWorkNumber;			//网台号
	ullong	m_StartFreq;				//起始频率		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ullong	m_StopFreq;					//终止频率		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ushort	m_JumpSpeed;				//跳速			单位：跳/秒；精度：0.1跳/秒；范围：[0,3000] 跳/秒
	uint	m_JumpFreqPeriod;			//跳频周期		单位：us；精度：1us；范围：[0,500000]us 
	uint	m_KeepTime;					//驻留时间		单位：us；精度：1us；范围：[0,500000]us
	ullong	m_JumpFreq1;				//跳频频率1		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ullong	m_JumpFreq2;				//跳频频率2		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ullong	m_JumpFreq3;				//跳频频率3		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ullong	m_JumpFreq4;				//跳频频率4		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz
	ullong	m_JumpFreq5;				//跳频频率5		单位：Hz，精度：1Hz 范围：[30000000, 3000000000]Hz

	JumpFreq_Coordination_Extend()
	{
		memset(this, 0, sizeof(JumpFreq_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(JumpFreq_Coordination_Extend));
	}
};
//Link16信号协同侦察信号参数
struct Link16_Coordination_Extend
{
	uint	m_RadiationNumber;				//辐射源编号
	Link16_Coordination_Extend()
	{
		memset(this, 0, sizeof(Link16_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Link16_Coordination_Extend));
	}
};
//航空反潜浮标信号协同侦察信号参数
struct Aviation_Coordination_Extend
{
	ullong	m_UpFreq;						//上行频率		单位：Hz，精度：1Hz 上行136MHz～173.5MHz
	ullong	m_LowFreq;						//下行频率		单位：Hz，精度：1Hz 下行291.4MHz
	Aviation_Coordination_Extend()
	{
		memset(this, 0, sizeof(Aviation_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Aviation_Coordination_Extend));
	}
};
//微波信号写侦察参数
struct Microwave_Coordination_Extend
{
	ullong	m_Freq;					//频率		单位：Hz，精度：1Hz 微波范围：[300000000, 300000000000]Hz 值域：[300MHz, 300GHz]
	ushort	m_ModelType;			//调制方式
	uint	m_SymbolSpeed;			//符号速率	单位：SPS
	Microwave_Coordination_Extend()
	{
		memset(this, 0, sizeof(Microwave_Coordination_Extend));
	}
	//从buf中读取数据
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Microwave_Coordination_Extend));
	}
};

#pragma pack(pop)

#endif //MSGDEFINE_H