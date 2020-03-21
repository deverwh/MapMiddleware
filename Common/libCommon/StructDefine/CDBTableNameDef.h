#ifndef CDBTableNameDef_H
#define CDBTableNameDef_H

#include "DBDef.h"
#include <QString>

/*-----------------------------素材库数据表结构-----------------------------*/

///////////////////////////////////素材库-采集数据编目///////////////////////////////////////

//光电侦察采集数据编目5.3.1.1.1
const QString TABLE_OF_COLLECTDATA = "SC_BM_GDCJ";
//光电侦察采集数据编目表结构
const QString OFCollectData_CollectMode = "CJMS";		//采集模式
const QString OFCollectData_ImageType = "TXLX";			//图像类型


//雷达信号采集数据编目5.3.1.1.3
const QString TABLE_RS_COLLECTDATA = "SC_BM_LDXHCJ";
//雷达信号采集数据编目表结构
const QString RSCollectData_CollectMode = "CJMS";		//采集模式
const QString RSCollectData_PdwNum = "SJGS";			//PDW数据个数
const QString RSCollectData_FileSize = "WJDX";			//文件大小

//IFF / TACAN信号采集数据编目5.3.1.1.5
const QString TABLE_ITR_COLLECTDATA = "SC_BM_DWTKXHCJ";
//IFF / TACAN信号采集数据编目表结构
const QString ITRCollectData_CollectMode = "CJMS";		//采集模式
const QString ITRCollectData_PdwNum = "SJGS";			//PDW数据个数
const QString ITRCollectData_FileSize = "WJDX";			//文件大小

//Link16信号采集数据编目5.3.1.1.7
const QString TABLE_TLR_COLLECTDATA = "SC_BM_LINK16CJ";
//Link16信号采集数据编目表结构
const QString TLRCollectData_CollectMode = "CJMS";		//采集模式
const QString TLRCollectData_CollectRate = "CYL";		//采样率
const QString TLRCollectData_FileSize = "WJDX";			//文件大小

//通信信号采集数据编目5.3.1.1.9
const QString TABLE_CSR_COLLECTDATA = "SC_BM_TXXHCJ";
const QString CSRCollectData_CollectMode = "CJMS";		//采集模式
const QString CSRCollectData_CollectRate = "CYL";		//采样率
const QString CSRCollectData_FileSize = "WJDX";			//文件大小

//话音采集数据编目5.3.1.1.11
const QString TABLE_VTR_COLLECTDATA = "SC_BM_HYXHCJ";
//话音采集数据编目表结构
const QString VTRCollectData_CollectMode = "CJMS";		//采集模式
const QString VTRCollectData_CollectRate = "CYL";		//采样率
const QString VTRCollectData_FileSize = "WJDX";			//文件大小

/*-----------------------------素材库数据表结构结束-----------------------------*/

/*-----------------------------情报库数据表结构-----------------------------*/

///////////////////////////////////情报库-文字/图像素材情报///////////////////////////////////////

//文字QB素材表名
const QString TABLE_TEXTMATERIAL = "QB_SC_WZ";
//文字QB素材表结构											  
const QString TextMaterial_ID = "ID";			//标识
const QString TextMaterial_CompanyCode = "DWDM";		//单位代码
const QString TextMaterial_ReconDirection = "ZCFXMC";		//ZC方向名称
const QString TextMaterial_MobilePlatformCode = "JDPTBH";		//机动平台代号
const QString TextMaterial_TaskNo = "SSRWBH";		//所属任务编号
const QString TextMaterial_SensorCode = "CGQDH";		//传感器代号
const QString TextMaterial_Route = "XL";			//线路
const QString TextMaterial_MessageFileType = "BZ";			//报种
const QString TextMaterial_MessageLanguageTypeCode = "WZ";			//文种
const QString TextMaterial_SendCompany = "FWDW";		//发文单位
const QString TextMaterial_MessageForm = "BWXS";		//报文形式
const QString TextMaterial_SecretLevel = "MMDJ";		//秘密等级
const QString TextMaterial_CopyTime = "CSSJ";		//抄收时间
const QString TextMaterial_SendTime = "FWSJ";		//发文时间
const QString TextMaterial_SendNo = "FWBH";		//发文编号
const QString TextMaterial_SignatureName = "QF";			//签发
const QString TextMaterial_Author = "BZ";			//编者
const QString TextMaterial_Title = "BT";			//标题
const QString TextMaterial_Topic = "ZTC";		//主题词
const QString TextMaterial_RecvCompany = "SWDW";		//收文单位
const QString TextMaterial_TimeEffectLevel = "SXDJ";		//时效等级
const QString TextMaterial_ReportType = "BWLX";		//报文类型
const QString TextMaterial_Means = "SD";			//手段
const QString TextMaterial_AllergyFlag = "MGBBS";		//敏感报标识
const QString TextMaterial_NationalRegion = "GJDQ";		//国家地区
const QString TextMaterial_ReportInfo = "BSXX";		//报送信息
const QString TextMaterial_Content = "ZW";			//正文
const QString TextMaterial_SourceMaterial = "SCLY";		//素材来源

///////////////////////////////////情报库-信号特征参数情报///////////////////////////////////////

//雷达信号特征参数5.3.3.2.1
const QString TABLE_RADAR_SIGCHARACTER = "QB_XHTZ_LD";
//雷达信号特征参数表结构
const QString RSSigChar_ID = "ID";						//标识
const QString RSSigChar_LocateTime = "DWSJ";			//定位时间
const QString RSSigChar_LocateLongitude = "MBJD";		//定位经度
const QString RSSigChar_LocateLatitude = "MBWD";		//定位纬度
const QString RSSigChar_Freq = "SPBCZ";					//频率
const QString RSSigChar_PRI = "PRIBCZ";					//重周
const QString RSSigChar_PluseWidth = "MKBCZ";			//脉宽
const QString RSSigChar_Attribute = "MBMC";				//属性(判)

//IFF信号特征参数5.3.3.2.2
const QString TABLE_IFF_SIGCHARACTER = "QB_XHTZ_MZIFF";
//IFF信号特征参数表结构
const QString IFFSigChar_ID = "ID";						//标识
const QString IFFSigChar_LocateTime = "DWSJ";			//侦获时间
const QString IFFSigChar_Freq = "SPPL";					//频率
const QString IFFSigChar_SignalType = "XHLX";			//信号类型
const QString IFFSigChar_LocateLongitude = "MBJD";		//定位经度
const QString IFFSigChar_LocateLatitude = "MBWD";		//定位纬度
const QString IFFSigChar_Attribute = "MBMC";			//属性(判)

//塔康信号特征参数5.3.3.2.3
const QString TABLE_TACAN_SIGCHARACTER = "QB_XHTZ_TACAN";
//塔康信号特征参数表结构
const QString TACANSigChar_ID = "ID";					//标识
const QString TACANSigChar_LocateTime = "DWSJ";			//定位时间
const QString TACANSigChar_LocateLongitude = "MBJD";	//定位经度
const QString TACANSigChar_LocateLatitude = "MBWD";		//定位纬度
const QString TACANSigChar_Height = "PTGD";				//高度
const QString TACANSigChar_SignalType = "XHLX";			//信号类型
//const QString TACANSigChar_LocateLatitude = "MBWD";		//模式代码
//const QString TACANSigChar_Height = "PTGD";				//呼号(判)
// const QString TACANSigChar_SignalType = "XHLX";			//注册号
//const QString TACANSigChar_Attribute = "MBMC";			//属性(判)

//短波通信信号特征参数5.3.3.2.4
const QString TABLE_SW_SIGCHARACTER = "QB_XH_DBTX";
//短波通信信号特征参数表结构
const QString SWSigChar_ID = "ID";						//标识
const QString SWSigChar_LocateTime = "DWSJ";			//侦获时间
const QString SWSigChar_Freq = "SPPL";					//频率
const QString SWSigChar_SignalType = "XHLX";			//信号类型
const QString SWSigChar_LocateLongitude = "MBJD";		//定位经度
const QString SWSigChar_LocateLatitude = "MBWD";		//定位纬度
const QString SWSigChar_Attribute = "MBMC";				//属性(判)

//超短波通信信号特征参数5.3.3.2.5
const QString TABLE_SSW_SIGCHARACTER = "QB_XH_CDBSJL";

//微波/卫星通信信号特征参数5.3.3.2.6
const QString TABLE_MICROWAVE_SIGCHARACTER = "QB_XH_WBTX";

//海事卫星信号特征参数5.3.3.2.7
const QString TABLE_SEASATELLITE_SIGCHARACTER = "QB_XH_HSWX";

//铱星信号特征参数5.3.3.2.8
const QString TABLE_MARITIMEIRIDIUM_SIGCHARACTER = "QB_XH_YXXH";

//反潜浮标信号特征参数5.3.3.2.9
const QString TABLE_SUBMARINEBUOY_SIGCHARACTER = "QB_XH_FQFB";


///////////////////////////////////情报库-综合文字情报///////////////////////////////////////

//综合文字情报表名
const QString TABLE_COLLITEXT = "QB_WZ_JBBW";
//综合文字情报表结构											  
const QString ColliText_ID = "ID";			//标识
const QString ColliText_SendCompany = "FWDW";		//发文单位
const QString ColliText_MessageForm = "BWXS";		//报文形式
const QString ColliText_SecretLevel = "MMDJ";		//秘密等级
const QString ColliText_CopyTime = "SBSJ";		//抄收时间
const QString ColliText_SendTime = "FWSJ";		//发文时间
const QString ColliText_SendNo = "FWBH";		//发文编号
const QString ColliText_SignatureName = "QFR";		//签发
const QString ColliText_Author = "BZ";			//编者
const QString ColliText_Title = "BT";			//标题
const QString ColliText_Topic = "ZTC";		//主题词
const QString ColliText_RecvCompany = "SWDW";		//收文单位
const QString ColliText_TimeEffectLevel = "SXDJ";		//时效等级
const QString ColliText_ReportType = "BWLX";		//报文类型
const QString ColliText_Means = "SD";			//手段
const QString ColliText_EbType = "EBFL";		//三部分类
const QString ColliText_SbType = "SBFL";		//情报部分类
const QString ColliText_AllergyFlag = "MGBBS";		//敏感报标识
const QString ColliText_NationalRegion = "GJDQ";		//国家地区
const QString ColliText_ReconDirection = "ZCFXMC";		//ZC方向名称
const QString ColliText_SecretParse = "MMPY";		//密码破译情报
const QString ColliText_SecretParseNo = "MMPYCGBH";	//密码破译成果编号
const QString ColliText_SpNetReconNo = "MBBH";		//特种网络侦察目标编号
const QString ColliText_TaskName = "RWMC";		//任务名称
const QString ColliText_ShareRsName = "ZCZYMC";	//共享侦察资源名称
const QString ColliText_ShareRsCompany = "ZCZYDW";		//共享侦察资源提供单位
const QString ColliText_SendMsg = "BSXX";		//报送信息
const QString ColliText_PositionPlatformNumber = "ZDPTDH";		//阵地（平台）代号
const QString ColliText_TaskID = "RWBH";		//任务编号
const QString ColliText_ReconArea = "ZCQY";		//ZC区域
const QString ColliText_ReportState = "SBZT";		//上报状态
const QString ColliText_Content = "NR";			//正文内容
const QString ColliText_PositionPlatformLongitude = "ZDPTJD";		//阵地(平台)经度
const QString ColliText_PositionPlatformLatitude = "ZDPTWD";		//阵地(平台)纬度
const QString ColliText_SaveTime = "RKSJ";		//入库时间


//综合文字情报附件表名
const QString TABLE_COLLITEXTAPPENDIX = "QB_WZ_FJXX";
//综合文字情报附件表数据结构
const QString ColliTextAppendix_ID = "ID";			//标识
const QString ColliTextAppendix_ConnectFlag = "GLID";		//综合文字情报标识
const QString ColliTextAppendix_FileType = "WJLX";		//文件类型
const QString ColliTextAppendix_FileName = "WJM";		//文件名
const QString ColliTextAppendix_FilePath = "WJLJ";		//文件路径
const QString ColliTextAppendix_FileSize = "WJDX";		//文件大小
const QString ColliTextAppendix_FileTime = "WJSC";		//文件时长
const QString ColliTextAppendix_SaveTime = "RKSJ";		//入库时间


//综合文字情报关联关系表名
const QString TABLE_COLLITEXTRELATION = "QB_WZ_GLGX";
//综合文字情报关联关系表结构											  
const QString ColliTextRelation_ID = "ID";			//标识
const QString ColliTextRelation_ConnectFlag = "GLID";		//综合文字情报标识
const QString ColliTextRelation_PrimaryName = "YBWBM";		//原报文表名
const QString ColliTextRelation_PrimaryFlag = "YBWBS";		//原报文标识
const QString ColliTextRelation_SaveTime = "RKSJ";		//入库时间


//综合文字情报上报情况表名
const QString TABLE_COLLITEXTRESPONSE = "QB_WZ_SBQK";
//综合文字情报上报情况表结构											  
const QString ColliTextResponse_ID = "ID";			//标识
const QString ColliTextResponse_ConnectFlag = "GLID";		//综合文字情报标识
const QString ColliTextResponse_ModifyFlag = "XGBWID";		//综合文字情报修改报文标识
const QString ColliTextResponse_ReportContent = "SBNR";		//上报内容
const QString ColliTextResponse_ExamineAttitude = "SGYJ";		//审稿意见
const QString ColliTextResponse_ExamineState = "SPZT";		//审批状态
const QString ColliTextResponse_SaveTime = "RKSJ";		//入库时间


///////////////////////////////////情报库-综合态势情报///////////////////////////////////////

//综合态势基本信息5.3.3.4.1
const QString TABLE_COLLISITUATION = "QB_TS_JBXX";
const QString ColliSituation_ID = "BS";				//标识
const QString ColliSituation_ReportState = "SBZT";	//上报状态

/*-----------------------------情报库数据表结构结束-----------------------------*/

/*-----------------------------目标信号知识库数据表结构-----------------------------*/

///////////////////////////////////目标信号知识库-实体目标知识///////////////////////////////////////
//实体目标固有特征5.3.4.2.1

//陆基平台目标特征表名5.3.4.2.1.1
const QString TABLE_LANDPLATTARGETCHARACTER = "MB_GY_LJPTTZ";

//海基平台目标特征表名5.3.4.2.1.2
const QString TABLE_OCEANPLATTARGETCHARACTER = "MB_GY_HJPTTZ";

//空基平台目标特征表名5.3.4.2.1.3
const QString TABLE_AIRPLATTARGETCHARACTER = "MB_GY_KJPTTZ";

//导弹/炮兵阵地特征表名5.3.4.2.1.4
const QString TABLE_DDTARGETCHARACTER = "MB_GY_DDZDTZ";

//雷达阵地特征表名5.3.4.2.1.5
const QString TABLE_LDTARGETCHARACTER = "MB_GY_LDZDTZ";

//机场特征表名5.3.4.2.1.6
const QString TABLE_JCTARGETCHARACTER = "MB_GY_JCTZ";

//港口特征表名5.3.4.2.1.7
const QString TABLE_GKTARGETCHARACTER = "MB_GY_GKTZ";

/*-----------------------------目标信号知识库数据表结构结束-----------------------------*/

/*-----------------------------管理库数据表结构-----------------------------*/

///////////////////////////////////管理库-资源数据///////////////////////////////////////
//
////装备情况
//const QString TABLE_EQUIPMENTSTATE = "GL_ZY_ZBSJ";
////装备情况详情表结构
//const QString EquipmentState_ID = "ID";			//标识
//const QString EquipmentState_EquipmentNumber = "ZBBH";		//装备编号
//const QString EquipmentState_ExtSystemNumber = "FXTBH";		//分系统编号
//const QString EquipmentState_EquipmentTypeNumber = "ZBLXBH";		//装备类型编号
//const QString EquipmentState_EquipmentName = "ZBMC";		//装备名称
//const QString EquipmentState_EquipmentType = "ZBZL";		//装备种类
//const QString EquipmentState_EquipmentWarehouse = "ZBSCCS";		//装备所处舱室
//const QString EquipmentState_EquipmentCabinetNumber = "ZBSCJGBH";	//装备所处机柜编号
//const QString EquipmentState_EquipmentCabinetName = "ZBSCJHMC";	//装备机柜名称
//const QString EquipmentState_Number = "ZBSL";		//装备数量
//const QString EquipmentState_CurrentState = "DQZT";		//当前状态
//
////侦察能力数据
//const QString TABLE_RECONABILITYDATA = "GL_ZY_ZCNLSJ";
////侦察能力数据结构
//const QString ReconAbilityData_Number = "ZCTXBH";		//侦察能力编号
//const QString ReconAbilityData_AerialType = "ZCTXLX";		//侦察天线类型
//const QString ReconAbilityData_InitialAzimuth = "QSFW";		//起始方位
//const QString ReconAbilityData_StopAzimuth = "JZFW";		//截止方位
//const QString ReconAbilityData_InitiaPitch = "QSFY";		//起始俯仰
//const QString ReconAbilityData_StopPitch = "JZFY";		//截止俯仰
//const QString ReconAbilityData_ToEarth = "DDZCJL";		//对地
//const QString ReconAbilityData_ToAir = "DKZCJL";		//对空
//const QString ReconAbilityData_ToSea = "DHZCJL";		//对海
//const QString ReconAbilityData_StartFreq = "QSPL";		//起始频率
//const QString ReconAbilityData_StopFreq = "JZPL";		//截止频率
//const QString ReconAbilityData_CheckFreqPrecision = "CPJD";		//测频经度
//const QString ReconAbilityData_CheckDirectionPrecision = "DWJD";		//定位经度
//
////装备能力关联
//const QString TABLE_EQUIPMENTABILITY = "GL_ZY_ZBNLGL";
////装备能力关联数据结构
//const QString EquipmentAbility_ID = "ID";			//标识
//const QString EquipmentAbility_ReconAbilityNumber = "CGQDH";		//侦察能力编号
//const QString EquipmentAbility_EquipmentNumber = "ZCTXBH";		//装备编号
//
////航迹数据
//const QString TABLE_TRACKSDATA = "GL_ZY_HJSJ";
////船平台航迹数据结构
//const QString TracksData_ID = "ID";			//标识
//const QString TracksData_MobilePlatformNumber = "JDPTBH";		//机动平台代号
//const QString TracksData_PlatformState = "PTZT";		//平台状态
//const QString TracksData_PlatformLongitude = "PTJD";		//平台经度
//const QString TracksData_PlatformLatitude = "PTWD";		//平台纬度
//const QString TracksData_PlatformRolling = "PTHY";		//平台横摇
//const QString TracksData_PlatformPitch = "PTZY";		//平台纵摇
//const QString TracksData_PlatformCourse = "PTHX";		//平台航向
//const QString TracksData_PlatformSpeed = "PTHS";		//平台航速
//const QString TracksData_WavehouseTime = "RKSJ";		//入库时间
//
////气象日志数据
//const QString TABLE_METEOROLOGICALLOG = "GL_ZY_QXRZSJ";
////气象日志详情数据结构
//const QString MeteorologicalLog_ID = "ID";			//标识
//const QString MeteorologicalLog_Time = "SJ";			//时间
//const QString MeteorologicalLog_Temperature = "QW";			//气温
//const QString MeteorologicalLog_RelativeHumidity = "XDSD";		//相对湿度
//const QString MeteorologicalLog_Pressure = "QY";			//气压
//const QString MeteorologicalLog_WindDirection = "FX";			//风向
//const QString MeteorologicalLog_WindSpeed = "FS";			//风速


////////////////////////////////管理库-指挥数据//////////////////////////////////////////

//指挥文电表名
const QString TABLE_TELEGRAM = "GL_ZK_ZHWD";
//指挥文电表数据结构										   
const QString Telegram_ID = "ZHWDID";		//标识
const QString Telegram_TaskCode = "RWDH";		//任务代号
const QString Telegram_ParentTaskCode = "FRWDH";		//父任务代号
const QString Telegram_TaskLevel = "RWDJ";		//任务等级
const QString Telegram_TaskType = "RWLX";		//任务类型
const QString Telegram_TaskStartTime = "RWKSSJ";		//任务计划开始时间
const QString Telegram_TaskEndTime = "RWJSSJ";		//任务计划结束时间
const QString Telegram_SendNo = "FWBH";		//发文编号
const QString Telegram_CreateTime = "CWSJ";		//成文时间
const QString Telegram_SendTime = "BGSJ";		//发报时间
const QString Telegram_Sender = "FWDW";		//发文单位
const QString Telegram_Receiver = "SWDW";		//收文单位
const QString Telegram_TimeEffectLevel = "SXDJ";		//时效等级
const QString Telegram_SecretLevel = "MMDJ";		//秘密等级		
const QString Telegram_Author = "BZ";			//编者
const QString Telegram_ReportType = "BWLX";		//报文类型
const QString Telegram_Title = "BT";			//标题
const QString Telegram_Content = "ZW";			//正文
const QString Telegram_RespondInfo = "HFXX";		//回复信息
const QString Telegram_BCheck = "SFCK";		//是否查看
const QString Telegram_TaskSource = "RWLY";		//任务来源
const QString Telegram_Recorder = "LRY";		//录入员
const QString Telegram_RecordTime = "LRSJ";		//录入时间
const QString Telegram_SendState = "FSZT";		//发送状态
const QString Telegram_SaveTime = "RKSJ";		//入库时间

//任务计划表名											   
const QString TABLE_TASKPLAN = "GL_ZK_JCRWJH";
//任务计划表数据结构										    
const QString TaskPlan_ID = "RWJHID";		//标识
const QString TaskPlan_TelegramFlag = "ZHWDID";		//ZH文电标识
const QString TaskPlan_Title = "RWJHBT";		//任务计划标题
const QString TaskPlan_Summarize = "RWJHGS";		//计划概述
const QString TaskPlan_Emphasis = "RWJHZD";		//任务重点
const QString TaskPlan_Request = "RWJHYQ";		//编成及要求
const QString TaskPlan_StartTime = "JHKSSJ";		//计划开始时间
const QString TaskPlan_EndTime = "JHJSSJ";		//计划结束时间
const QString TaskPlan_MobilePlatformCode = "JDPTDH";		//机动平台代号
const QString TaskPlan_EquipComRequest = "PTBZXQ";		//装备、通信保障及需求
const QString TaskPlan_AdvancePlan = "TQCZYA";		//特情处置预案
const QString TaskPlan_ActualizeRequest = "SSYQ";		//实施要求
const QString TaskPlan_OpinionAdvice = "YJJY";		//意见建议
const QString TaskPlan_NextWork = "XYBGZ";		//下一步工作
const QString TaskPlan_RecordTime = "LRSJ";		//录入时间
const QString TaskPlan_ConfigMgr = "PZGL";		//配置管理
const QString TaskPlan_RecordCompany = "LRDW";		//录入单位
const QString TaskPlan_TaskType = "RWLB";		//任务类别
const QString TaskPlan_TaskNo = "RWBH";		//任务编号
const QString TaskPlan_BRead = "SFCK";		//是否查看
const QString TaskPlan_ActiveArea = "HDQY";		//活动区域
const QString TaskPlan_PlanLine = "JHHX";		//计划航线
const QString TaskPlan_PlanState = "JHZT";		//计划状态
const QString TaskPlan_SaveTime = "RKSJ";		//入库时间


//任务计划区域关系表名
const QString TABLE_PLANAREARELATION = "GL_ZK_JHQYGX";
//任务计划区域关系表结构
const QString PlanAreaRelation_ID = "ID";			//标识
const QString PlanAreaRelation_TackPlanID = "RWJHID";		//任务计划ID
const QString PlanAreaRelation_ReconDirectionName = "ZCFXMC";		//侦察方向名称
const QString PlanAreaRelation_ReconArea = "ZCQY";		//侦察区域
const QString PlanAreaRelation_SaveTime = "RKSJ";		//入库时间

//任务计划目标关系表名
const QString TABLE_TASKPLANTARGETRELATION = "GL_ZK_JHMBGX";
//任务计划目标关系表结构
const QString TaskPlanTargetRelation_ID = "ID";			//标识
const QString TaskPlanTargetRelation_PlanID = "RWJHID";		//任务计划ID
const QString TaskPlanTargetRelation_ReconTargetName = "ZCMBMC";		//侦察目标名称
const QString TaskPlanTargetRelation_reconTargetcode = "ZCMBNM";		//侦察目标内码
const QString TaskPlanTargetRelation_SaveTime = "RKSJ";		//入库时间

//指控数据附件表名
const QString TABLE_APPENDIX = "GL_ZK_FJ";
//指控数据附件表数据结构
const QString Appendix_ID = "FJID";		//附件ID
const QString Appendix_ConnectFlag = "GLWJ";		//关联的记录标识
const QString Appendix_AppendixModule = "SSMK";		//所属模块
const QString Appendix_FileType = "WJLX";		//文件类型
const QString Appendix_FileName = "WJM";		//文件名
const QString Appendix_FileSize = "WJDX";		//文件大小
const QString Appendix_FileTime = "WJSC";		//文件时长
const QString Appendix_FilePath = "WJLJ";		//文件路径
const QString Appendix_UploadTime = "SCSJ";		//上传时间
const QString Appendix_FTPFrontDecorate = "FTP";		//FTP前缀


//任务执行表名
const QString TABLE_TASKEXEC = "GL_ZK_RWZX";
//任务执行表数据结构
const QString TaskExec_ID = "ID";			//标识
const QString TaskExec_ReconDirectionName = "ZCFXMC";		//ZC方向名称
const QString TaskExec_ReconArea = "ZCQY";		//ZC区域
const QString TaskExec_PositionPlatformNumber = "ZDPTDH";		//阵地（平台）代号
const QString TaskExec_TaskName = "RWMC";		//任务名称
const QString TaskExec_TaskNo = "RWBH";		//任务编号
const QString TaskExec_DataUpdateTime = "RKSJ";		//数据更新时间

//指挥命令表名											   
const QString TABLE_COMMANDORDER = "GL_ZK_ZHML";
//指挥命令表数据结构										    
const QString CommandOrder_ID = "ID";			//标识
const QString CommandOrder_ConnectTelegramFlag = "ZHWDBS";		//关联ZH文电标识
const QString CommandOrder_CreateTime = "CWSJ";		//成文时间
const QString CommandOrder_SendTime = "XDSJ";		//下达时间
const QString CommandOrder_ReceivingSubSystem = "JSFXT";		//接收分系统
const QString CommandOrder_TimeEffectLevel = "SXDJ";		//时效等级
const QString CommandOrder_Author = "BZ";			//编者
const QString CommandOrder_Title = "BT";			//标题
const QString CommandOrder_Content = "ZW";			//正文
const QString CommandOrder_SaveTime = "RKSJ";		//入库时间

//侦察计划表名											   
const QString TABLE_RECONPLAN = "GL_ZK_ZCJH";
//侦察计划表数据结构										    
const QString ReconPlan_ID = "ID";		//ZC计划标识				
const QString ReconPlan_ConnectTelegramFlag = "ZHWDBS";	//关联ZH文电标识
const QString ReconPlan_TaskPlanFlag = "RWJHBS";	//任务计划标识
const QString ReconPlan_StartTime = "KSSJ";		//开始时间
const QString ReconPlan_EndTime = "JSSJ";		//结束时间
const QString ReconPlan_Area = "ZCQY";		//ZC区域
const QString ReconPlan_ObjectLongitude = "ZCDXJD";	//ZC对象经度
const QString ReconPlan_ObjectLatitude = "ZCDXWD";	//ZC对象纬度
const QString ReconPlan_ReceivingSubSystem = "JSFXT";		//接收分系统
const QString ReconPlan_ReceivingStation = "JSTW";		//接收台位
const QString ReconPlan_DeliveryTime = "XDSJ";		//下达时间
const QString ReconPlan_TimeEffectLevel = "SXDJ";		//时效等级
const QString ReconPlan_Author = "BZ";		//编者
const QString ReconPlan_Title = "BT";		//标题
const QString ReconPlan_Type = "JHRWLX";	//ZC计划类型
const QString ReconPlan_Content = "ZW";		//正文

//侦察计划参数关系表名
const QString TABLE_RECONPLANPARMETER = "GL_ZK_ZCJHCSGX";
//侦察计划参数关系表结构
const QString ReconPlanParmeter_ID = "ID";			//标识
const QString ReconPlanParmeter_RconPlanID = "RWJHID";		//侦察计划ID
const QString ReconPlanParmeter_ReconPlanParmeterName = "JHCSMC";		//侦察计划参数表名
const QString ReconPlanParmeter_ParmeterFlag = "JHCSBZ";		//侦察计划参数标识

//雷达侦察表名
const QString TABLE_RADARRECON = "GL_ZK_LDZCJH";
//雷达侦察计划参数表数据结构                     
const QString RadarReconPlanParam_ID = "ID";		//标识
const QString RadarReconPlanParam_ReconTargetcode = "ZCMBNM";	//ZC目标内码
const QString RadarReconPlanParam_ReconObject = "ZCDX";		//ZC对象
const QString RadarReconPlanParam_ReconAntType = "ZCTX";		//ZC天线类型
const QString RadarReconPlanParam_StartFrequency = "QSPL";		//起始频率
const QString RadarReconPlanParam_EndFrequency = "ZZPL";		//终止频率

//通信普查表名
const QString TABLE_COMMSURVEY = "GL_ZK_TXPCJH";
//通信普查计划参数表数据结构
const QString CommSurveyPlanParam_ID = "ID";			//标识
const QString CommSurveyPlanParam_ReconTargetcode = "ZCMBNM";		//ZC目标内码
const QString CommSurveyPlanParam_ReconObject = "ZCDX";		//ZC对象
const QString CommSurveyPlanParam_ReconAntType = "ZCTX";		//ZC天线类型
const QString CommSurveyPlanParam_StartFrequency = "QSPL";		//起始频率
const QString CommSurveyPlanParam_EndFrequency = "ZZPL";		//终止频率
const QString CommSurveyPlanParam_PlanParamSource = "JHCSLY";		//计划参数来源

//通信详查表名
const QString TABLE_COMMUNICATESIFT = "GL_ZK_TXXCJH";
//通信详查计划参数表数据结构
const QString CommunicateSiftPlanParam_ID = "ID";			//标识
const QString CommunicateSiftPlanParam_ReconTargetcode = "ZCMBNM";		//ZC目标内码
const QString CommunicateSiftPlanParam_ReconObject = "ZCDX";		//ZC对象
const QString CommunicateSiftPlanParam_ReconAntType = "ZCTX";		//ZC天线类型
const QString CommunicateSiftPlanParam_CenterFrequency = "ZXPL";		//中心频率
const QString CommunicateSiftPlanParam_BandWidth = "DK";			//带宽
const QString CommunicateSiftPlanParam_ModulationMode = "TZFS";		//调制方式
const QString CommunicateSiftPlanParam_SymbolRate = "FHSL";		//符号速率
const QString CommunicateSiftPlanParam_PlanParamSource = "JHCSLY";		//计划参数来源

//IFF/TACAN监视表名
const QString TABLE_IFFTACANMONITOR = "GL_ZK_IFFTACAN";
//IFF/TACAN监视计划参数表数据结构
const QString IffTacanMonitorPlanParam_ID = "ID";			//标识
const QString IffTacanMonitorPlanParam_Targetcode = "ZCMBNM";		//侦察目标内码
const QString IffTacanMonitorPlanParam_TechnicalSystem = "JSTZ";		//技术体制
const QString IffTacanMonitorPlanParam_RadioFreqArray = "SPPL";		//射频频率集
const QString IffTacanMonitorPlanParam_StorageTime = "RKSJ";		//入库时间
const QString IffTacanMonitorPlanParam_RadiationSourceName = "FSYMC";		//辐射源名称

//光电侦察表名
const QString TABLE_PHOTOELECTRICRECON = "GL_ZK_GDTXZC";
//光电图像计划参数表数据结构  
const QString PhotoelectricImagePlanParam_ID = "ID";			//标识
const QString PhotoelectricImagePlanParam_ReconTargetcode = "ZCMBNM";		//ZC目标内码
const QString PhotoelectricImagePlanParam_ReconObject = "ZCDX";		//ZC对象
const QString PhotoelectricImagePlanParam_ReconAzimuth = "RWFW";		//侦察方位
const QString PhotoelectricImagePlanParam_PlanArea = "RWQY";		//任务区域
const QString PhotoelectricImagePlanParam_DetectionMode = "ZZMS";		//侦照模式
const QString PhotoelectricImagePlanParam_PlanParamSource = "JHCSLY";		//计划参数来源

//跳频信号侦察表名
const QString TABLE_FREQHOPPING = "GL_ZK_TPXHZC";
//跳频信号计划参数表数据结构
const QString FrequencyHoppingPlanParam_ID = "ID";			//标识
const QString FrequencyHoppingPlanParam_Targetcode = "ZCMBNM";		//侦察目标内码
const QString FrequencyHoppingPlanParam_ReconObject = "ZCDX";		//侦察对象
const QString FrequencyHoppingPlanParam_StartFrequency = "QSPL";		//起始频率
const QString FrequencyHoppingPlanParam_EndFrequency = "ZZPL";		//终止频率
const QString FrequencyHoppingPlanParam_HopSpeed = "TS";			//跳速
const QString FrequencyHoppingPlanParam_HopFrequencyPeriod = "TPZQ";		//跳频周期
const QString FrequencyHoppingPlanParam_PlanParamSource = "JHCSLY";		//计划参数来源

//扩频信号侦察
const QString TABLE_SPREADSPECTRUM = "GL_ZK_KPXHZ";
//扩频信号计划参数表数据结构
const QString SpreadSpectrumPlanParam_ID = "ID";			//标识
const QString SpreadSpectrumPlanParam_Targetcode = "ZCMBNM";		//侦察目标内码
const QString SpreadSpectrumPlanParam_ReconObject = "ZCDX";		//侦察对象
const QString SpreadSpectrumPlanParam_CenterFrequency = "ZXPL";		//中心频率
const QString SpreadSpectrumPlanParam_BandWidth = "DK";			//带宽
const QString SpreadSpectrumPlanParam_ModulationMode = "TZFS";		//调制方式
const QString SpreadSpectrumPlanParam_SymbolRate = "FHSL";		//符号速率
const QString SpreadSpectrumPlanParam_SpreadingCodeLength = "KPMC";		//扩频码长
const QString SpreadSpectrumPlanParam_SpreadingCodeSequence = "KPMSL";		//扩频码序列
const QString SpreadSpectrumPlanParam_PlanParamSource = "JHCSLY";		//计划参数来源

//命令反馈日志
const QString TABLE_COMMANDRESPOND = "GL_ZK_MLFKRZ";
//命令反馈日志表数据结构									  
const QString CommandRespondLog_ID = "ID";			//标识
const QString CommandRespondLog_ConnectCommandOrderID = "GLMLBS";		//关联命令标识
const QString CommandRespondLog_ConnectCommandOrderType = "GLMLLX";		//关联命令类型
const QString CommandRespondLog_ExecState = "ZXZT";		//执行状态
const QString CommandRespondLog_FeedbackTime = "FKSJ";		//反馈时间
const QString CommandRespondLog_ReceivingSubSystem = "JSFXT";		//接收分系统
const QString CommandRespondLog_ReceivingStation = "JSTW";	// 接收台位
const QString CommandRespondLog_FeedbackContent = "FKZW";		//反馈正文
const QString CommandRespondLog_Remark = "BZ";			//备注

//值班日志
const QString TABLE_ORDERLYLOG = "GL_ZK_ZBRZ";
//值班日志表数据结构
const QString Orderlylog_ID = "ID";			//值班日志ID
const QString Orderlylog_PositionPlatformNumber = "ZDPTDH";		//阵地（平台）代号
const QString Orderlylog_TaskName = "RWMC";		//任务名称
const QString Orderlylog_TaskNo = "RWBH";		//任务编号
const QString Orderlylog_SubSystemNo = "FXTBH";		//分系统编号
const QString Orderlylog_StationNo = "FXTTWBH";	//台位编号
const QString Orderlylog_Author = "ZXR";		//撰写人
const QString Orderlylog_CreateTime = "ZXSJ";		//撰写时间
const QString Orderlylog_Title = "RZBT";		//日志标题
const QString Orderlylog_FinishedWork = "YWCGZ";		//已完成工作
const QString Orderlylog_UndoWork = "DWCGZ";		//待完成工作
const QString Orderlylog_Remark = "BZ";			//备注
const QString Orderlylog_SaveTime = "RKSJ";		//入库时间

//平台任务简报
const QString TABLE_TASKBRIEF = "GL_ZK_RWJB";
//平台任务简报表数据结构
const QString TaskBrief_ID = "ID";			//任务简报ID
const QString TaskBrief_PositionPlatformNumber = "ZDPTDH";		//阵地（平台）代号
const QString TaskBrief_TaskName = "RWMC";		//任务名称
const QString TaskBrief_TaskNo = "RWBH";		//任务编号
const QString TaskBrief_TaskStartTime = "KSSJ";		//任务开始时间
const QString TaskBrief_TaskEndTime = "JSSJ";		//任务结束时间
const QString TaskBrief_TelegramFlag = "RWDH";		//所属指挥文电标识
const QString TaskBrief_TaskPlanFlag = "RWJHNM";		//所属任务计划标识
const QString TaskBrief_FlexiblePlatformCode = "JDPTBH";		//机动平台代号
const QString TaskBrief_ReportMadeCompany = "BGZZDW";		//报告制作单位
const QString TaskBrief_ReportMaker = "BGZZR";		//报告制作人
const QString TaskBrief_ReportMadeTime = "BGZZSJ";		//报告制作时间
const QString TaskBrief_ReportContent = "BGNR";		//报告内容
const QString TaskBrief_ReconDirection = "ZCFX";		//侦察方向
const QString TaskBrief_ReconObject = "ZCDX";		//侦察对象
const QString TaskBrief_StartPlace = "CFD";		//出发地
const QString TaskBrief_BackPlace = "FHD";		//返回地
const QString TaskBrief_TotalRoute = "ZHC";		//总航程
const QString TaskBrief_SaveTime = "RKSJ";		//入库时间

//内部协同
const QString TABLE_INNERCOOPERATE = "GL_ZK_NBXT";
//内部协同参数表数据结构
const QString InnerCooperateParam_ID = "ID";			//标识
const QString InnerCooperateParam_ConnectReconPlanFlag = "GLZCJHBS";	//关联ZC计划标识
const QString InnerCooperateParam_CreateTime = "CWSJ";		//成文时间
const QString InnerCooperateParam_SendTime = "XDSJ";		//下达时间
const QString InnerCooperateParam_ReceivingSubSystem = "JSFXT";		//接收分系统
const QString InnerCooperateParam_ReceivingStation = "JSTW";		//接收台位
const QString InnerCooperateParam_TimeEffectLevel = "SXDJ";		//时效等级
const QString InnerCooperateParam_Author = "BZ";			//编者
const QString InnerCooperateParam_Title = "BT";			//标题
const QString InnerCooperateParam_Content = "ZW";			//正文


//////////////////////////////////管理库-监测数据////////////////////////////////////////

//文件传输任务
const QString TABLE_TRANSFERTASK = "GL_JCSJ_CSRW";
//文件传输任务表数据结构
const QString TransferTask_ID = "BS";			//标识
const QString TransferTask_TaskType = "RWLX";		//传输任务类型
const QString TransferTask_DataSource = "SJLY";		//文件来源
const QString TransferTask_FileType = "WJLX";		//文件类型
const QString TransferTask_FileSize = "WJJDX";		//文件大小
const QString TransferTask_FileName = "WJMC";		//文件名称
const QString TransferTask_ReceiveCompany = "JSDW";		//接收单位
const QString TransferTask_TimeEffectLevel = "SXDJ";		//时效等级
const QString TransferTask_TransmintState = "RWZT";		//传输状态
const QString TransferTask_TransmintProccess = "RWJD";		//传输进度
const QString TransferTask_KALink = "KALL";		//传输采用的链路
const QString TransferTask_Remark = "BZ";			//备注
const QString TransferTask_SaveTime = "RKSJ";		//入库时间


//加卸载数据记录
const QString TABLE_LOADUNLOADDATARECORD = "GL_JCSJ_XZSJJL";
//加卸载数据记录表数据结构
const QString LoadUnloadDataRecord_ID = "ID";			//标识
const QString LoadUnloadDataRecord_PositionPlatformNumber = "ZDPTDH";		//阵地（平台）代号
const QString LoadUnloadDataRecord_Operator = "CZY";		//操作员
const QString LoadUnloadDataRecord_Type = "JXZLX";		//加卸载类型
const QString LoadUnloadDataRecord_Content = "JXZLN";		//加卸载内容
const QString LoadUnloadDataRecord_Time = "CZSJ";		//加卸载时间
const QString LoadUnloadDataRecord_DataDestination = "SJQX";		//数据来源/去向
const QString LoadUnloadDataRecord_Remark = "BZ";			//备注



//////////////////////////////////管理库-工作日志数据////////////////////////////////////////

//雷达信号侦察操作日志5.3.5.4.2
const QString TABLE_RS_OPERATELOG = "GL_RZ_LDXHZCCZ";
//雷达信号侦察操作日志表数据结构
const QString RSOperateLog_PlatNo = "ZDPTDH";				//阵地（平台）代号
const QString RSOperateLog_TaskID = "RWBH";					//侦察任务编号/训练任务标识
const QString RSOperateLog_EventID = "SJID";				//侦察操作事件ID
const QString RSOperateLog_ScoutStationNo = "ZHYLJS";		//侦察岗位ID
const QString RSOperateLog_EventContent = "SJMS";			//侦察操作事件描述
	
//光电侦察操作日志5.3.5.4.3
const QString TABLE_OF_OPERATELOG = "GL_RZ_GDZCCZ";
//光电侦察操作日志表数据结构
const QString OFOperateLog_PlatNo = "ZDPTDH";				//阵地（平台）代号
const QString OFOperateLog_TaskID = "RWBH";					//侦察任务编号/训练任务标识
const QString OFOperateLog_EventID = "SJID";				//侦察操作事件ID
const QString OFOperateLog_ScoutStationNo = "ZHYLJS";		//侦察岗位ID
const QString OFOperateLog_EventContent = "SJMS";			//侦察操作事件描述

//通信信号侦察操作日志5.3.5.4.4
const QString TABLE_CSR_OPERATELOG = "GL_RZ_TXXHZCCZ";
//通信信号侦察操作日志表数据结构
const QString CSROperateLog_PlatNo = "ZDPTDH";				//阵地（平台）代号
const QString CSROperateLog_TaskID = "RWBH";				//侦察任务编号/训练任务标识
const QString CSROperateLog_EventID = "SJID";				//侦察操作事件ID
const QString CSROperateLog_ScoutStationNo = "ZHYLJS";		//侦察岗位ID
const QString CSROperateLog_EventContent = "SJMS";			//侦察操作事件描述

//Link16信号侦察操作日志5.3.5.4.5
const QString TABLE_TLR_OPERATELOG = "GL_RZ_LINK16XHZCCZ";
//Link16信号侦察操作日志表数据结构
const QString TLROperateLog_PlatNo = "ZDPTDH";				 //阵地（平台）代号
const QString TLROperateLog_TaskID = "RWBH";				 //侦察任务编号/训练任务标识
const QString TLROperateLog_EventID = "SJID";				 //侦察操作事件ID
const QString TLROperateLog_ScoutStationNo = "ZHYLJS";		 //侦察岗位ID
const QString TLROperateLog_EventContent = "SJMS";			 //侦察操作事件描述

//IFF/TACAN信号侦察操作日志5.3.5.4.6
const QString TABLE_ITR_OPERATELOG = "GL_RZ_DWTKXHZCCZ";
//IFF/TACAN信号侦察操作日志表数据结构
const QString ITROperateLog_PlatNo = "ZDPTDH";				  //阵地（平台）代号
const QString ITROperateLog_TaskID = "RWBH";				  //侦察任务编号/训练任务标识
const QString ITROperateLog_EventID = "SJID";				  //侦察操作事件ID
const QString ITROperateLog_ScoutStationNo = "ZHYLJS";		  //侦察岗位ID
const QString ITROperateLog_EventContent = "SJMS";			  //侦察操作事件描述

//任务管理操作日志5.3.5.4.7
const QString TABLE_TM_OPERATELOG = "GL_RZ_RWGLCZ";
//任务管理操作日志表数据结构
const QString TMOperateLog_PlatNo = "ZDPTDH";					//阵地（平台）代号
const QString TMOperateLog_TaskID = "RWBH";						//侦察任务编号/训练任务标识
const QString TMOperateLog_EventID = "SJID";					//侦察操作事件ID
const QString TMOperateLog_ScoutStationNo = "ZHYLJS";			//侦察岗位ID
const QString TMOperateLog_EventContent = "SJMS";				//侦察操作事件描述

//情报处理操作日志5.3.5.4.8
const QString TABLE_QB_OPERATELOG = "GL_RZ_QBCLCZ";
//情报处理操作日志表数据结构
const QString QBOperateLog_PlatNo = "ZDPTDH";					//阵地（平台）代号
const QString QBOperateLog_TaskID = "RWBH";						//侦察任务编号/训练任务标识
const QString QBOperateLog_EventID = "SJID";					//侦察操作事件ID
const QString QBOperateLog_ScoutStationNo = "ZHYLJS";			//侦察岗位ID
const QString QBOperateLog_EventContent = "SJMS";				//侦察操作事件描述

//任务通信操作日志5.3.5.4.9
const QString TABLE_CS_OPERATELOG = "GL_RZ_RWCLCZ";
//任务通信操作日志表数据结构
const QString CSOperateLog_PlatNo = "ZDPTDH";					//阵地（平台）代号
const QString CSOperateLog_TaskID = "RWBH";						//侦察任务编号/训练任务标识
const QString CSOperateLog_EventID = "SJID";					//侦察操作事件ID
const QString CSOperateLog_ScoutStationNo = "ZHYLJS";			//侦察岗位ID
const QString CSOperateLog_EventContent = "SJMS";				//侦察操作事件描述

///////////////////////////////////管理库-运维数据///////////////////////////////////////

//任务系统健康日志5.3.5.8.1
const QString TABLE_TASKSYSTEM_HEALTHLOG = "GL_YW_RWXTJK";
//任务系统健康日志表结构
const QString TaskSystemHealthLog_RSState = "LDSYS";	//雷达信号侦测分系统状态
const QString TaskSystemHealthLog_CSRState = "TXSYS";	//通信信号侦测分系统状态
const QString TaskSystemHealthLog_TLRState = "LINK16SYS";	//Link16信号侦测分系统状态
const QString TaskSystemHealthLog_ITRState = "DWTKSYS";	//IFF/TACAN信号侦测分系统状态
const QString TaskSystemHealthLog_OFState = "GDSYS";	//光电侦察分系统状态
const QString TaskSystemHealthLog_CISState = "ZKQBSYS";	//指挥控制与情报处理分系统状态
const QString TaskSystemHealthLog_CSState = "RWTXSYS";	//任务通信分系统状态

//雷侦分系统健康日志5.3.5.8.2
const QString TABLE_RS_HEALTHLOG = "GL_YW_LZJK";
//雷侦分系统健康日志表结构
const QString RSHealthLog_SaveTime = "RKSJ";		//入库时间

//通侦分系统健康日志5.3.5.8.3
const QString TABLE_CSR_HEALTHLOG = "GL_YW_TZJK";
//通侦分系统健康日志表结构
const QString CSRHealthLog_SaveTime = "RKSJ";		//入库时间

//Link16分系统健康日志5.3.5.8.4
const QString TABLE_TLR_HEALTHLOG = "GL_YW_LINK16JK";
//Link16分系统健康日志表结构
const QString TLRHealthLog_SaveTime = "RKSJ";		//入库时间

//IFF/TACAN分系统健康日志5.3.5.8.5
const QString TABLE_ITR_HEALTHLOG = "GL_YW_DWTKJK";
//IFF/TACAN分系统健康日志表结构
const QString ITRHealthLog_SaveTime = "RKSJ";		//入库时间

//光侦分系统健康日志5.3.5.8.6
const QString TABLE_OF_HEALTHLOG = "GL_YW_GZJK";
//光侦分系统健康日志表结构
const QString OFHealthLog_SaveTime = "RKSJ";		//入库时间

//指挥控制与情报处理分系统健康日志5.3.5.8.7
const QString TABLE_CIS_HEALTHLOG = "GL_YW_ZKQBJK";
//指挥控制与情报处理分系统健康日志表结构
const QString CISHealthLog_SaveTime = "RKSJ";		//入库时间

//任务通信分系统健康日志5.3.5.8.8
const QString TABLE_CS_HEALTHLOG = "GL_YW_RWTXJK";
//任务通信分系统健康日志表结构
const QString CSHealthLog_SaveTime = "RKSJ";		//入库时间

///////////////////////////////////管理库-基础库///////////////////////////////////////

//字典名称
const QString TABLE_DICTIONARYNAME = "ZD_ZDMC";
//字典名称表数据结构
const QString DictionaryName_ID = "ZDID";		//字典ID
const QString DictionaryName_Name = "ZDMC";		//字典名称
const QString DictionaryName_Discription = "ZDSM";		//字典说明
const QString DictionaryName_ParentID = "FZDID";		//父字典ID
const QString DictionaryName_BUsed = "SFQY";		//是否启用
const QString DictionaryName_RefferenceStandard = "CKBZ";		//参考标准


//字典值
const QString TABLE_DICTIONARYVALUE = "ZD_ZDZ";
//字典值表数据结构
const QString DictionaryValue_ValueID = "ZDZID";		//字典值ID
const QString DictionaryValue_DictionaryID = "ZDID";		//字典ID
const QString DictionaryValue_ShortCut = "QZ";		//取值
const QString DictionaryValue_CodeValue = "BMZ";		//编码值
const QString DictionaryValue_Sequence = "XH";		//序号

/*-----------------------------管理库数据表结构定义结束-----------------------------*/

#endif // CDBTableNameDef_H