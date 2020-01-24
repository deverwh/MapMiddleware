#ifndef XmlNodeDef_h__
#define XmlNodeDef_h__

#include <QString>
#include "ConfigDef.h"


//xml文件中节点名称定义

//与zip文件同名xml文件节点定义
const QString XN_MessageInfo = QStringLiteral("./node/报头信息");
const QString XN_MessageType = QStringLiteral("信息类型");
const QString XN_Appendix = QStringLiteral("./node/其他附件文件/其他附件");
const QString XN_AppendName = QStringLiteral("其他附件名");
const QString XN_AppendType = QStringLiteral("其他附件类型");


//信息类型定义
const QString XN_MsgType_Command = QStringLiteral("指挥文电");
const QString XN_MsgType_TaskPlan = QStringLiteral("任务计划");
const QString XN_MsgType_TaskSum = QStringLiteral("任务总结");

//指挥文电节点定义
const QString XN_Cmd_Command = QStringLiteral("./node/任务计划协同");
const QString XN_Cmd_TimeEffectLevel = QStringLiteral("时效等级");
const QString XN_Cmd_CreateTime = QStringLiteral("报告时间");
const QString XN_Cmd_TaskCode = QStringLiteral("任务代号");
const QString XN_Cmd_Title = QStringLiteral("标题");
const QString XN_Cmd_Author = QStringLiteral("编者");
const QString XN_Cmd_TaskEndTime = QStringLiteral("任务结束时间");
const QString XN_Cmd_ParentTaskCode = QStringLiteral("父任务代号");
const QString XN_Cmd_Inputer = QStringLiteral("录入员");
const QString XN_Cmd_TaskLevel = QStringLiteral("任务等级");
const QString XN_Cmd_Sender = QStringLiteral("发文单位");
const QString XN_Cmd_TaskStartTime = QStringLiteral("任务开始时间");
const QString XN_Cmd_SecretLevel = QStringLiteral("秘密等级");
const QString XN_Cmd_RespondInfo = QStringLiteral("回复信息");
const QString XN_Cmd_Content = QStringLiteral("正文");
const QString XN_Cmd_ID = QStringLiteral("指挥文电ID");
const QString XN_Cmd_TaskType = QStringLiteral("任务类型");
const QString XN_Cmd_SaveTime = QStringLiteral("录入时间");
const QString XN_Cmd_SendNo = QStringLiteral("发文编号");
const QString XN_Cmd_Receiver = QStringLiteral("收文单位");

//任务计划文件
const QString XN_TP_TaskPlan = QStringLiteral("./任务计划");
const QString XN_TP_ConfigMgr = QStringLiteral("配置管理");
const QString XN_TP_NextWork = QStringLiteral("下一步工作");
const QString XN_TP_Emphasis = QStringLiteral("任务重点");
const QString XN_TP_PlanState = QStringLiteral("计划状态");
const QString XN_TP_EquipComRequest = QStringLiteral("装备通信保障需求");
const QString XN_TP_AdvancePlan = QStringLiteral("特情处置预案");
const QString XN_TP_TaskType = QStringLiteral("任务类别");
const QString XN_TP_ActualizeRequest = QStringLiteral("实施要求");
const QString XN_TP_Title = QStringLiteral("任务计划标题");
const QString XN_TP_ID = QStringLiteral("任务计划ID");
const QString XN_TP_EndTime = QStringLiteral("结束时间");
const QString XN_TP_Request = QStringLiteral("任务计划要求");
const QString XN_TP_OpinionAdvice = QStringLiteral("意见建议");
const QString XN_TP_SaveCompany = QStringLiteral("录入单位");
const QString XN_TP_Summarize = QStringLiteral("任务计划概述");
const QString XN_TP_StartTime = QStringLiteral("开始时间");
const QString XN_TP_TelegramFlag = QStringLiteral("指挥文电ID");
const QString XN_TP_MobilePlatformCode = QStringLiteral("阵地平台代号");
const QString XN_TP_ActiveArea = QStringLiteral("活动区域");
const QString XN_TP_SaveTime = QStringLiteral("录入时间");
const QString XN_TP_TaskNo = QStringLiteral("任务编号");
const QString XN_TP_PlanCourse = QStringLiteral("计划航线");


//综合情报XML模板
const QString XML_SendNumber = QStringLiteral("发送方");
const QString XML_ReceiveNumber = QStringLiteral("接收方");
const QString XML_SendTime = QStringLiteral("发送时间");
const QString XML_Secrity = QStringLiteral("密级");
const QString XML_MsgType = QStringLiteral("信息类型");
//文字情报外部信息项
const QString XML_SendPlat = QStringLiteral("发文单位");
const QString XML_BWType = QStringLiteral("报文形式");
const QString XML_TBType = QStringLiteral("通报形式");
const QString XML_SecrityDJ = QStringLiteral("秘密等级");
const QString XML_ReceiveTime = QStringLiteral("收报时间");
const QString XML_ReconTime = QStringLiteral("侦收时间");
const QString XML_SendTimeQB = QStringLiteral("发文时间");
const QString XML_SendCode = QStringLiteral("发文编号");
const QString XML_Asign = QStringLiteral("签发");
const QString XML_AsignWork = QStringLiteral("签发人职务");
const QString XML_Editor = QStringLiteral("编者");
const QString XML_Title = QStringLiteral("标题");
const QString XML_TopC = QStringLiteral("主题词");
const QString XML_ReceivePlat = QStringLiteral("收文单位");
const QString XML_TimeDJ = QStringLiteral("时效等级");
const QString XML_ReportType = QStringLiteral("报文类型");
const QString XML_Hand = QStringLiteral("手段");
const QString XML_ThreeType = QStringLiteral("三部分类");
const QString XML_SecondType = QStringLiteral("二部分类");
const QString XML_Sensitivty = QStringLiteral("敏感报标识");
const QString XML_CountryArea = QStringLiteral("国家地区");
const QString XML_Drection = QStringLiteral("方向");
const QString XML_CodeIntelliqence = QStringLiteral("密码破译情报");
const QString XML_CodeNumber = QStringLiteral("密码破译成果编号");
const QString XML_ReconNumber = QStringLiteral("特种网络侦察目标编号");
const QString XML_Correlation = QStringLiteral("相关任务");
const QString XML_RemindTime = QStringLiteral("提醒时间");
const QString XML_Extend1 = QStringLiteral("扩展字段1");
const QString XML_CoreIntelliqence = QStringLiteral("核心来源情报");
const QString XML_IntelliqenceForm = QStringLiteral("情报来源");
const QString XML_OraInfo = QStringLiteral("口报信息");
const QString XML_PlatNumber = QStringLiteral("平台代号");
const QString XML_TaskNumber = QStringLiteral("任务编号");
//校译格式报

//模板附件说明
const QString XML_AffixName = QStringLiteral("模板附件名");
const QString XMl_AffixType = QStringLiteral("模板附件类型");
const QString XML_AffixDescribe = QStringLiteral("模板附件描述");

#endif // XmlNodeDef_h__
