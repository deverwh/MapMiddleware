#ifndef XmlNodeDef_h__
#define XmlNodeDef_h__

#include <QString>
#include "ConfigDef.h"


//xml�ļ��нڵ����ƶ���

//��zip�ļ�ͬ��xml�ļ��ڵ㶨��
const QString XN_MessageInfo = QStringLiteral("./node/��ͷ��Ϣ");
const QString XN_MessageType = QStringLiteral("��Ϣ����");
const QString XN_Appendix = QStringLiteral("./node/���������ļ�/��������");
const QString XN_AppendName = QStringLiteral("����������");
const QString XN_AppendType = QStringLiteral("������������");


//��Ϣ���Ͷ���
const QString XN_MsgType_Command = QStringLiteral("ָ���ĵ�");
const QString XN_MsgType_TaskPlan = QStringLiteral("����ƻ�");
const QString XN_MsgType_TaskSum = QStringLiteral("�����ܽ�");

//ָ���ĵ�ڵ㶨��
const QString XN_Cmd_Command = QStringLiteral("./node/����ƻ�Эͬ");
const QString XN_Cmd_TimeEffectLevel = QStringLiteral("ʱЧ�ȼ�");
const QString XN_Cmd_CreateTime = QStringLiteral("����ʱ��");
const QString XN_Cmd_TaskCode = QStringLiteral("�������");
const QString XN_Cmd_Title = QStringLiteral("����");
const QString XN_Cmd_Author = QStringLiteral("����");
const QString XN_Cmd_TaskEndTime = QStringLiteral("�������ʱ��");
const QString XN_Cmd_ParentTaskCode = QStringLiteral("���������");
const QString XN_Cmd_Inputer = QStringLiteral("¼��Ա");
const QString XN_Cmd_TaskLevel = QStringLiteral("����ȼ�");
const QString XN_Cmd_Sender = QStringLiteral("���ĵ�λ");
const QString XN_Cmd_TaskStartTime = QStringLiteral("����ʼʱ��");
const QString XN_Cmd_SecretLevel = QStringLiteral("���ܵȼ�");
const QString XN_Cmd_RespondInfo = QStringLiteral("�ظ���Ϣ");
const QString XN_Cmd_Content = QStringLiteral("����");
const QString XN_Cmd_ID = QStringLiteral("ָ���ĵ�ID");
const QString XN_Cmd_TaskType = QStringLiteral("��������");
const QString XN_Cmd_SaveTime = QStringLiteral("¼��ʱ��");
const QString XN_Cmd_SendNo = QStringLiteral("���ı��");
const QString XN_Cmd_Receiver = QStringLiteral("���ĵ�λ");

//����ƻ��ļ�
const QString XN_TP_TaskPlan = QStringLiteral("./����ƻ�");
const QString XN_TP_ConfigMgr = QStringLiteral("���ù���");
const QString XN_TP_NextWork = QStringLiteral("��һ������");
const QString XN_TP_Emphasis = QStringLiteral("�����ص�");
const QString XN_TP_PlanState = QStringLiteral("�ƻ�״̬");
const QString XN_TP_EquipComRequest = QStringLiteral("װ��ͨ�ű�������");
const QString XN_TP_AdvancePlan = QStringLiteral("���鴦��Ԥ��");
const QString XN_TP_TaskType = QStringLiteral("�������");
const QString XN_TP_ActualizeRequest = QStringLiteral("ʵʩҪ��");
const QString XN_TP_Title = QStringLiteral("����ƻ�����");
const QString XN_TP_ID = QStringLiteral("����ƻ�ID");
const QString XN_TP_EndTime = QStringLiteral("����ʱ��");
const QString XN_TP_Request = QStringLiteral("����ƻ�Ҫ��");
const QString XN_TP_OpinionAdvice = QStringLiteral("�������");
const QString XN_TP_SaveCompany = QStringLiteral("¼�뵥λ");
const QString XN_TP_Summarize = QStringLiteral("����ƻ�����");
const QString XN_TP_StartTime = QStringLiteral("��ʼʱ��");
const QString XN_TP_TelegramFlag = QStringLiteral("ָ���ĵ�ID");
const QString XN_TP_MobilePlatformCode = QStringLiteral("���ƽ̨����");
const QString XN_TP_ActiveArea = QStringLiteral("�����");
const QString XN_TP_SaveTime = QStringLiteral("¼��ʱ��");
const QString XN_TP_TaskNo = QStringLiteral("������");
const QString XN_TP_PlanCourse = QStringLiteral("�ƻ�����");


//�ۺ��鱨XMLģ��
const QString XML_SendNumber = QStringLiteral("���ͷ�");
const QString XML_ReceiveNumber = QStringLiteral("���շ�");
const QString XML_SendTime = QStringLiteral("����ʱ��");
const QString XML_Secrity = QStringLiteral("�ܼ�");
const QString XML_MsgType = QStringLiteral("��Ϣ����");
//�����鱨�ⲿ��Ϣ��
const QString XML_SendPlat = QStringLiteral("���ĵ�λ");
const QString XML_BWType = QStringLiteral("������ʽ");
const QString XML_TBType = QStringLiteral("ͨ����ʽ");
const QString XML_SecrityDJ = QStringLiteral("���ܵȼ�");
const QString XML_ReceiveTime = QStringLiteral("�ձ�ʱ��");
const QString XML_ReconTime = QStringLiteral("����ʱ��");
const QString XML_SendTimeQB = QStringLiteral("����ʱ��");
const QString XML_SendCode = QStringLiteral("���ı��");
const QString XML_Asign = QStringLiteral("ǩ��");
const QString XML_AsignWork = QStringLiteral("ǩ����ְ��");
const QString XML_Editor = QStringLiteral("����");
const QString XML_Title = QStringLiteral("����");
const QString XML_TopC = QStringLiteral("�����");
const QString XML_ReceivePlat = QStringLiteral("���ĵ�λ");
const QString XML_TimeDJ = QStringLiteral("ʱЧ�ȼ�");
const QString XML_ReportType = QStringLiteral("��������");
const QString XML_Hand = QStringLiteral("�ֶ�");
const QString XML_ThreeType = QStringLiteral("��������");
const QString XML_SecondType = QStringLiteral("��������");
const QString XML_Sensitivty = QStringLiteral("���б���ʶ");
const QString XML_CountryArea = QStringLiteral("���ҵ���");
const QString XML_Drection = QStringLiteral("����");
const QString XML_CodeIntelliqence = QStringLiteral("���������鱨");
const QString XML_CodeNumber = QStringLiteral("��������ɹ����");
const QString XML_ReconNumber = QStringLiteral("�����������Ŀ����");
const QString XML_Correlation = QStringLiteral("�������");
const QString XML_RemindTime = QStringLiteral("����ʱ��");
const QString XML_Extend1 = QStringLiteral("��չ�ֶ�1");
const QString XML_CoreIntelliqence = QStringLiteral("������Դ�鱨");
const QString XML_IntelliqenceForm = QStringLiteral("�鱨��Դ");
const QString XML_OraInfo = QStringLiteral("�ڱ���Ϣ");
const QString XML_PlatNumber = QStringLiteral("ƽ̨����");
const QString XML_TaskNumber = QStringLiteral("������");
//У���ʽ��

//ģ�帽��˵��
const QString XML_AffixName = QStringLiteral("ģ�帽����");
const QString XMl_AffixType = QStringLiteral("ģ�帽������");
const QString XML_AffixDescribe = QStringLiteral("ģ�帽������");

#endif // XmlNodeDef_h__
