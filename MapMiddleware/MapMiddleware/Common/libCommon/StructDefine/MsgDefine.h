////////////////////////////////////////////����ӿڽṹ�嶨��//////////////////////////////
/*
*
*	waring:	��Ҫ���ź������ʹ�ýṹ����Ϊ����ʱ�����ڽṹ�嶨��β������Q_DECLARE_METATYPE(structName);		//ע���Զ���ṹ��  ���ź������ʹ��
*/

#ifndef MSGDEFINE_H
#define MSGDEFINE_H

#include "InfoCode.h"
#include <QtCore>
#include <memory>

#pragma region ������Ϣ

using uint = unsigned int;		//ʹ���޷��ŵ�int���ͱ���
using uchar = unsigned char;	//ʹ���޷��ŵ�char���ͱ���
using ushort = unsigned short;	//ʹ���޷��ŵ�short���ͱ���
using ullong = unsigned long long;	//ʹ���޷��ŵ�long���ͱ���

#define BROADCAST_DESTLOGIC_ID 0

#define BROADCAST_SRCPLUGIN_ID 0xA001
#define BROADCAST_DESTPLUGIN_ID 0xA001

//�ṹ�尴��1�ֽڶ���
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
		// ֡ͷ
		m_header.m_FrameLength = frameLen;
		frame.append((char *)&m_header, sizeof(m_header));
		// ����
		frame.append((char *)&m_data, sizeof(m_data));
		// ��չ����
		frame.append(m_extData);
		// ֡β
		frame.append((char *)&m_end, sizeof(m_end));

		return frame;
	}

	QByteArray dataByteArray()
	{
		QByteArray frame;
		// ����
		frame.append((char *)&m_data, sizeof(m_data));
		// ��չ����
		frame.append(m_extData);
		return frame;
	}
};

/*������Ϣͷ
*		����ucMsgType(��Ϣ���)�������£�
* ucMsgType=0xA1;			ָ�ӿ�����Ϣ
* ucMsgType=0xA2;			ϵͳ�����Ϣ
* ucMsgType=0xA3;			�ֶ������Ϣ
* ucMsgType=0xA4;			�鱨������Ϣ
* ucMsgType=0xA6;			����������Ϣ
* ucMsgType=0xA7;			����ͨ����Ϣ
* ucMsgType=0xA8;			ϵͳͨ����Ϣ
* ucMsgType=0xA9;			��Դ������Ϣ
* ucMsgType=0xB0;			����ʶ����Ϣ
* ucMsgType=0xC0;			̬�ƽ�����Ϣ
* ucMsgType=0xD0;			��ʱͨ������Ϣ
*/
struct MsgHeader
{
	uint	m_FrameHead;				//֡ͷ				4
	uint	m_SourceID;					//Դ�߼�ID			4
	uint	m_DstID;					//Ŀ���߼�ID			4
	uint	m_FrameLength;				//֡��				4
	uchar	m_MsgType;					//��Ϣ���			1
	uchar	m_MsgSubSystem;				//��Ϣ����			1

	//���캯��
	MsgHeader()
	{
		memset(this, 0, sizeof(MsgHeader));
		this->m_FrameHead = 0x55555555;		//֡ͷΪ�̶�ֵ
	}
	//���ع��캯��
	MsgHeader(const uint &sourceID,const uint &dstID,const uint frameLength,
		const uchar &msgType, const uchar &msgSubSytem)
	{
		memset(this, 0, sizeof(MsgHeader));
		this->m_FrameHead = 0x55555555;		//֡ͷΪ�̶�ֵ
		this->m_SourceID = sourceID;
		this->m_DstID = dstID;
		this->m_FrameLength = frameLength;
		this->m_MsgType = msgType;
		this->m_MsgSubSystem = msgSubSytem;
	}
	//�������ݵ��ṹ����
	void DataFromBuf(char *buf)
	{
		memcpy(this, buf, sizeof(MsgHeader));
	}
};

//������Ϣβ
struct MsgEnd 
{
	uint	m_FrameEnd;			//֡β			4
	MsgEnd()
	{
		this->m_FrameEnd = 0xFFFFFFFF;			//ʹ�ù̶�ֵ
	}
};

//��Ϣ��������Ϣ������Ϣ������϶��ɣ�������

const static uint  commandNumberLength = 22;		//�����ŵ��ֽڳ��� 
const static uint  taskNameLength = 100;			//�������Ƶ��ֽڳ���
const static uint  taskNumberLength = 50;			//�����ŵ��ֽڳ���
const static uint  dataBaseTableNameLength = 60;	//���ݿ�������ֽڳ���
const static uint  recordFlag = 32;					//��¼��ʶ���ֽڳ���
const static uint  remarkLength = 100;				//��ע�ֽڳ���
const static uint  fileName = 256;					//�ļ������ֽڳ���
const static uint  filePath = 256;					//�ļ�·���ֽڳ���

#pragma endregion

//////////////////////////////////Data�����ֶζ���////////////////////////////////////////

#pragma region ָ�ӿ�����Ϣ

//ָ���ĵ�֪ͨ		�����ʶ��A7 - 01)
struct ZHNotify  		
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint    m_SendFlatNumber;								//����ƽ̨���	��ͨ��ƽ̨�ţ���Ч��0
	uint    m_ReceiveFlatNumber;							//����ƽ̨���	��ͨ��ƽ̨�ţ���Ч��0
	char	m_FilePath[256];								//�ļ�·��		����Ϊ�գ�������·��������0��ʼ��䣬������0
	char	m_FileName[256];								//�ļ���		��0��ʼ��䣬������0
	ZHNotify()
	{
		memset(this, 0, sizeof(ZHNotify));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ZHNotify));
	}
};
Q_DECLARE_METATYPE(ZHNotify);		//ע���Զ���ṹ��  ���ź������ʹ��
//ָ���ĵ�֪ͨ�ַ�		�����ʶ��A1-01)
struct ZHNotifyDistribute
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint	m_Time;										//ʱ��		Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_TaskName[taskNameLength];						//��������  �ӵ�һ���ֽڿ�ʼ��䣬������0����ָ���ĵ�ı��⡣
	char   m_TaskNumber[taskNumberLength];					//������	�ӵ�һ���ֽڿ�ʼ��䣬������0	
	ushort  m_TimeOrder;									//ʱЧ�ȼ�  01���ؼ�����02���Ӽ�����03��������04��ƽ��
	ushort  m_MysterOrder;									//���ܵȼ�  01�����ܣ���02�����ܣ���03�����ܣ���04���ڲ�����05��������
	ushort  m_AffixFlag;									//������־  0���޸�������1���и�����
	char	m_DataBaseTableName[dataBaseTableNameLength];	//���ݿ����  ���ݱ���ָ�ӵ��ĵĿ������
	char   m_RecordFlag[recordFlag];						//��¼��ʶ  ��д���ݱ���ָ�ӵ��ļ�¼��ʶ�ֶΣ��ӵ�һ���ֽڿ�ʼ��䣬������0,ͨ����¼��ȡ�������ݺ�ָ�Ӹ�����Ϣ��

	//���캯�� ȫ����ʼ��Ϊ0
	ZHNotifyDistribute()
	{
		memset(this, 0, sizeof(ZHNotifyDistribute));
	}

	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ZHNotifyDistribute));
	}
};
Q_DECLARE_METATYPE(ZHNotifyDistribute);		//ע���Զ���ṹ��  ���ź������ʹ��
//ָ���ĵ�֪ͨ����		�����ʶ��A1-02)
struct ZHNotifyFeedBack
{
	char	m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint    m_Time;											//ʱ��		Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	ushort  m_RoleNumber;									//��ɫ���  0����Ч��ɫ����1���״��ź���������ɫ����2���״��źŸ�������ɫ��
																		//3��ͨ���ź�����ɫ����4�������ź�����ɫ����5��link16�ź�����ɫ��
																		//6(IFF��TACAN�ź�����ɫ����7���������ɫ����8����������ɫ����9���鱨�����ɫ��
	ushort  m_FeedBackFlag;									//����״̬  1��δ�ģ���2�����ģ�������ֵ��Ч��ȱʡֵ0 ��

	//���캯�� ȫ����ʼ��Ϊ0
	ZHNotifyFeedBack()
	{
		memset(this, 0, sizeof(ZHNotifyFeedBack));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ZHNotifyFeedBack));
	}
};
Q_DECLARE_METATYPE(ZHNotifyFeedBack);		//ע���Զ���ṹ��  ���ź������ʹ��

//����ƻ�֪ͨ�ַ�		�����ʶ��A1-03)
struct TaskPlanNotifyDistribute
{
	char	m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint    m_Time;											//ʱ��		Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char	m_DataBaseTableName[dataBaseTableNameLength];	//���ݿ����  ���ݱ�������ƻ��Ŀ������
	char	m_RecordFlag[recordFlag];						//��¼��ʶ  ��д���ݱ�������ƻ�����¼��ʶ�ֶΣ��ӵ�һ���ֽڿ�ʼ��䣬������0��

	//���캯�� ȫ����ʼ��Ϊ0
	TaskPlanNotifyDistribute()
	{
		memset(this, 0, sizeof(TaskPlanNotifyDistribute));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(TaskPlanNotifyDistribute));
	}
};
Q_DECLARE_METATYPE(TaskPlanNotifyDistribute);		//ע���Զ���ṹ��  ���ź������ʹ��
//����ƻ�֪ͨ����       �����ʶ��A1-04��
struct TaskPlanNofifyFeedBack
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint    m_Time;											//ʱ��		Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	ushort  m_RoleNumber;									//��ɫ���  0����Ч��ɫ����1���״��ź���������ɫ����2���״��źŸ�������ɫ��
	//3��ͨ���ź�����ɫ����4�������ź�����ɫ����5��link16�ź�����ɫ��
	//6(IFF��TACAN�ź�����ɫ����7���������ɫ����8����������ɫ����9���鱨�����ɫ��
	ushort  m_FeedBackFlag;									//����״̬  1��δ�ģ���2�����ģ�������ֵ��Ч��ȱʡֵ0 ��
	char	m_Remark[remarkLength];							//��ע   �貹��˵��������д���ֶΣ��ӵ�һ���ֽڿ�ʼ��䣬������0
	//���캯�� ȫ����ʼ��Ϊ0
	TaskPlanNofifyFeedBack()
	{
		memset(this, 0, sizeof(TaskPlanNofifyFeedBack));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(TaskPlanNofifyFeedBack));
	}
};
Q_DECLARE_METATYPE(TaskPlanNofifyFeedBack);		//ע���Զ���ṹ��  ���ź������ʹ��
//�ֶ�����ƻ�ִ�з���		�����ʶ��A1-F0)
struct ArtificePlanFeedBack
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	ushort	m_RoleNumber;									//��ɫ���
	char   m_TaskPlanID[32];								//����ƻ�ID	����ƻ����ı�ʶ
	ushort  m_ExecuteState;									//ִ��״̬		0=��Ч��1 = δִ��(����֪ͨ5���δִ�����Զ�������״̬)��2 = ִ���У�3 = ִ����ɣ�4 = ִ����ͣ(�˹���ͣ���Զ���ִͣ�����Զ��ϱ���״̬)��5 = ִ����ֹ(�˹���ֹ���ϱ���״̬)

	ArtificePlanFeedBack()
	{
		memset(this, 0, sizeof(ArtificePlanFeedBack));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ArtificePlanFeedBack));
	}
};
Q_DECLARE_METATYPE(ArtificePlanFeedBack);		//ע���Զ���ṹ��  ���ź������ʹ��

//�ļ���������������		�����ʶ��A1-05)
struct TransmitFileRequire
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint    m_Time;											//ʱ��		  Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	uint    m_ReceiveFlatNumber;							//����ƽ̨��  �������������Աƽ̨��
	char   m_FileName[fileName];							//�ļ�����    �����ļ���������չ��
	char   m_FilePath[filePath];							//�ļ�·��
	char   m_Remark[remarkLength];							//��ע        �貹��˵��������д���ֶΣ��ӵ�һ���ֽڿ�ʼ��䣬������0
	//���캯�� ȫ����ʼ��Ϊ0
	TransmitFileRequire()
	{
		memset(this, 0, sizeof(TransmitFileRequire));
	}
	void DataFromBuf(const char* buf)
	{
		memcpy(this, buf, sizeof(TransmitFileRequire));
	}
};
Q_DECLARE_METATYPE(TransmitFileRequire);		//ע���Զ���ṹ��  ���ź������ʹ��
Q_DECLARE_METATYPE(Msg<TransmitFileRequire>);

//�ļ�������������			�����ʶ��A1-06��
struct TransmitFileFeedBack
{
	enum PendType
	{
		Type_Invalid,	// ��Ч
		Type_Agree,		// ͬ��
		Type_Refuse,	// �ܾ�
	};

	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint    m_Time;											//ʱ��		  Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	uint    m_ReceiveFlatNumber;							//����ƽ̨��  �������������Աƽ̨��
	ushort  m_ExamineResult;								//�������    0����Ч����1��ͬ�⣩��2���ܾ���
	char   m_Remark[remarkLength];							//��ע        �貹��˵��������д���ֶΣ��ӵ�һ���ֽڿ�ʼ��䣬������0
	//���캯�� ȫ����ʼ��Ϊ0
	TransmitFileFeedBack()
	{
		memset(this, 0, sizeof(TransmitFileFeedBack));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(TransmitFileFeedBack));
	}
};
Q_DECLARE_METATYPE(TransmitFileFeedBack);		//ע���Զ���ṹ��  ���ź������ʹ��
Q_DECLARE_METATYPE(Msg<TransmitFileFeedBack>);		//ע���Զ���ṹ��  ���ź������ʹ��

//֧Ԯ�鱨֪ͨ�ַ�(����֧Ԯ�鱨)			�����ʶ��A1-07)
struct SupportIntelligenceNotify
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint    m_Time;											//ʱ��		  Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_LeadObjectNumber[4];							//����Ŀ�����
	char   m_ObjectSrcNumber[22];							//Ŀ�꣨ԭ�����
	char   m_ObjectName[20];								//Ŀ������
	char   m_CountryArea[8];								//���ҵ�������֯
	char   m_Obtain;										//��ȡ�ֶ�
	//���캯�� ȫ����ʼ��Ϊ0
	SupportIntelligenceNotify()
	{
		memset(this, 0, sizeof(SupportIntelligenceNotify));
	}
};
Q_DECLARE_METATYPE(SupportIntelligenceNotify);		//ע���Զ���ṹ��  ���ź������ʹ��

//����Ŀ��λ�õ���Ϣ    ����֧Ԯ�鱨��һ����
struct ObjectPoit
{
	uint	m_Time;				//λ��ʱ��	Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	int     m_Longitude;		//����		ȡֵ��Χ��[-180000000��180000000]����Ӧֵ��[-180��180]��d)	��λ/���ȣ�0.000001�㣻��Чֵ��181000000��˵��������Ϊ��������Ϊ����
	int     m_Latitude;			//γ��		ȡֵ��Χ��[-90000000��90000000]����Ӧֵ��[-90��90]����λ / ���ȣ�0.000001�㣻��Чֵ��91000000��˵������γΪ������γΪ����
	int     m_Height;			//�����	ȡֵ��Χ/ֵ��[-3000,70000]����λ / ���ȣ� 1�ף���Чֵ�� - 10000��˵�����߶���д��ֵ�������д��ֵ��
	//Ĭ�ϳ�ʼ��
	ObjectPoit()
	{
		this->m_Time = 0;
		this->m_Longitude = 181000000;
		this->m_Latitude = 91000000;
		this->m_Height = -10000;
	}
};

#pragma endregion

#pragma region �鱨������Ϣ

//�鱨�ز��ϱ�֪ͨ
struct CompreHensive_QB_ReportNotify
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	ushort	m_SystemNumber;									//��ϵͳ���
	uint	m_iTime;										//ʱ��		 Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_DatabaseTableName[60];						//���ݿ���� �ӵ�һ���ֽڿ�ʼ��䣬������0
	char   m_RecordFlag[32];								//��¼��ʶ   ���ݱ�ı�ʶ�ֶ����ݣ��ӵ�һ���ֽڿ�ʼ��䣬������0
	CompreHensive_QB_ReportNotify()
	{
		memset(this, 0, sizeof(CompreHensive_QB_ReportNotify));
	}
};
Q_DECLARE_METATYPE(CompreHensive_QB_ReportNotify);		//ע���Զ���ṹ��  ���ź������ʹ��

//�ۺ��鱨�ϱ�
struct ComprehensiveIntelligenceReport
{
	char	m_CommandNumber[commandNumberLength];				//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	uint	m_iTime;											//ʱ��		 Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char	m_DatabaseTableName[60];							//���ݿ���� �ӵ�һ���ֽڿ�ʼ��䣬������0
	char	m_RecordFlag[32];									//��¼��ʶ   ���ݱ�ı�ʶ�ֶ����ݣ��ӵ�һ���ֽڿ�ʼ��䣬������0
	ComprehensiveIntelligenceReport()
	{
		memset(this, 0, sizeof(ComprehensiveIntelligenceReport));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(ComprehensiveIntelligenceReport));
	}
};
Q_DECLARE_METATYPE(ComprehensiveIntelligenceReport);		//ע���Զ���ṹ��  ���ź������ʹ��
Q_DECLARE_METATYPE(Msg<ComprehensiveIntelligenceReport>);

//�ۺ��鱨�ϱ�����
struct CompreHensive_QB_ReportFeedBack
{
	enum Type
	{
		Type_Agree	= 0,	// ͬ��
		Type_Refuse = 1		// �ܾ�
	};

	char	m_CommandNumber[commandNumberLength];			//������	������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ�
	ushort	m_FeedBack;										//�������	0��ͬ�⣩��1����ͬ�⣩
	char	m_Remark[100];									//��ע		�貹��˵��������д���ֶΣ��ӵ�һ���ֽڿ�ʼ��䣬������0
	CompreHensive_QB_ReportFeedBack()
	{
		memset(this, 0, sizeof(CompreHensive_QB_ReportFeedBack));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(CompreHensive_QB_ReportFeedBack));
	}
};
Q_DECLARE_METATYPE(CompreHensive_QB_ReportFeedBack);		//ע���Զ���ṹ��  ���ź������ʹ��
Q_DECLARE_METATYPE(Msg<CompreHensive_QB_ReportFeedBack>);

#pragma endregion

//ѵ�����ݲɼ�֪ͨ������ѵ��ϵͳ���ݲɼ���   �����ʶ��D0-01��
struct TrainDataCollectNotify
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;											//ʱ��		  Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	ushort  m_SubSystemNumber;								//��ϵͳ���
	ushort  m_CollectContrl;								//�ɼ�����    0����Ч����1����������2��������
	int     m_AreaLongitude;								//����		ȡֵ��Χ��[-180000000��180000000]����Ӧֵ��[-180��180]��d)	��λ/���ȣ�0.000001�㣻��Чֵ��181000000��˵��������Ϊ��������Ϊ����
	int     m_AreaLatitude;									//γ��		ȡֵ��Χ��[-90000000��90000000]����Ӧֵ��[-90��90]����λ / ���ȣ�0.000001�㣻��Чֵ��91000000��˵������γΪ������γΪ����

	TrainDataCollectNotify()
	{
		memset(this, 0, sizeof(TrainDataCollectNotify));
	}
};

//�ɼ�������Ӧ��Ϣ  �����ʶ��D0 - FF��
struct stCollectCtrlFeedback
{
	char m_CommandNumber[commandNumberLength];			//������   ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_FeedBackCode;								//��Ӧ������

	stCollectCtrlFeedback()
	{
		memset(this, 0, sizeof(stCollectCtrlFeedback));
	}

	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(stCollectCtrlFeedback));
	}
};

//ѵ�����ݲɼ�֪ͨ��������  Ϊѵ�����ݲɼ�֪ͨ�еĲɼ����Ʋ���
struct TrainDataNofigyStart
{
	uchar	m_ObjecCode;					//Ŀ��������
	uint	m_SingalFeaturesExtend;			//�ź�������չ�������ͱ�ʶ	��λ��ʾ����λȡֵΪ1ʱ��ʾ�߱����ź�������չ������λΪ0ʱ��ʾ�����ڴ��ź�������չ���ġ�
	TrainDataNofigyStart()
	{
		memset(this, 0, sizeof(TrainDataNofigyStart));
	}
};
/*                               ����/��λ��չ�ֶ�                 */
//���̲��źŲ�����չ
struct  Ultrashort_Parameter_Extend
{
	uchar	m_SingalType;			//�ź�����
	ullong	m_Freq;					//Ƶ��		���ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ushort	m_ModelType;			//���Ʒ�ʽ
	Ultrashort_Parameter_Extend()
	{
		memset(this, 0, sizeof(Ultrashort_Parameter_Extend));
	}
};
//�����ƶ��źŲ�����չ
struct SatelliteMove_Parameter_Extend
{
	uchar	m_SingalType;				//�ź�����
	ullong	m_UpFreq;					//����Ƶ��	��λ��Hz�����ȣ�1Hz ��Χ:[100000000, 18000000000]Hz
	ullong	m_LowFreq;					//����Ƶ��	��λ��Hz�����ȣ�1Hz ��Χ:[100000000, 18000000000]Hz

	SatelliteMove_Parameter_Extend()
	{
		memset(this, 0, sizeof(SatelliteMove_Parameter_Extend));
	}
};
//�״��źŲ�����չ
struct Radar_Parameter_Extend
{
	uchar	m_RadioFreqCode;				//��Ƶ���ʹ���
	uint	m_RadioFreqStandard;			//��Ƶ���ֵ	ȡֵ��Χ��[40000��40000000] ��Ч��0�����ȣ�0.001MHz��
											//	��λ��MHz ��Ӧֵ��[400��40000]����Ƶȡֵ1��6��д˳�����£�����Ƶȡֵ����6��ʱ��������ѡ6����ͬȡֵ������Ƶȡֵ����6��ʱ������Ƶȡֵ1����Ƶȡֵ6������д��ʣ�����Ƶȡֵ����Чֵ - 10000
	uchar	m_RepeatIntervalType;			//�ظ��������
	uint	m_RepeatIntervalStandard;		//�ظ�������ֵ	��λ/���ȣ�1ns����Чֵ0; ȡֵ��Χ��[3300��50000000]��
	uchar	m_PulseType;					//���������ʹ���
	uint	m_PulseStandard;				//�����ȱ��ֵ		��λ/���ȣ�1ns����Χ��[100��2000000]
	char	m_TypeName[20];					//��������
	Radar_Parameter_Extend()
	{
		memset(this, 0, sizeof(Radar_Parameter_Extend));
	}
};
//����IFF�źŲ�����չ
struct AmericalIFF_Parameter_Extend
{
	uchar	m_ModelNumber;				//ģʽ�Ŵ���
	char	m_ModelCode[10];			//ģʽ��
	ushort	m_AirplanCode;				//�ɻ�����
	char	m_Address[6];				//��ַ��
	AmericalIFF_Parameter_Extend()
	{
		memset(this, 0, sizeof(AmericalIFF_Parameter_Extend));
	}
};
//����IFF�źŲ�����չ
struct RussiaIFF_Parameter_Extend
{
	uchar	m_ModelNumber;					//ģʽ����
	ushort	m_AirplanCode;					//�ɻ�����		����BCD���룬(0001-7777),�����еķɻ�����һ��ȷ���Ͳ���仯
	ullong	m_Freq;							//Ƶ��			��λ��Hz�����ȣ�1Hz ��Χ:[650000000, 2700000000]Hz
	uint	m_WorkModel;					//����ģʽ
	RussiaIFF_Parameter_Extend()
	{
		memset(this, 0, sizeof(RussiaIFF_Parameter_Extend));
	}
};
//�����źŲ�����չ
struct Navigation_Parameter_Extend
{
	uchar	m_SingalType;				//�ź�����
	uint	m_RadioFreq;				//��ƵƵ��		��λ��Hz�����ȣ�1Hz ��Χ:[962000000, 1213000000]Hz
	uchar	m_TACANModel;				//TACAN����ģʽ	��Χ��[0,255]����¼A��TACAN/DME����ģʽ
	char	m_Morsecode[4];				//Ī��˹��
	Navigation_Parameter_Extend()
	{
		memset(this, 0, sizeof(Navigation_Parameter_Extend));
	}
};
//�������źŲ�����չ
struct DataLink_Parameter_Extend
{
	uchar	m_SingalType;				//�ź�����
	ullong	m_Freq;						//Ƶ��			��λ��Hz�����ȣ�1Hz �̲���Χ:[1500000, 30000000]Hz ���̲���Χ��[30000000, 3000000000]Hz
	ushort	m_NodeType;					//�ڵ�����		-1=��Ч,1=����վ,2=ǰ�ڿ���վ;
	ushort	m_MyselfAddress;			//�����ַ		����PU��
	ushort	m_CallAddress;				//���е�ַ		����PU��
	DataLink_Parameter_Extend()
	{
		memset(this, 0, sizeof(DataLink_Parameter_Extend));
	}
};
//��Ƶ�źŲ�����չ
struct JumpFreq_Parameter_Extend
{
	ullong	m_StartFreq;					//��ʼƵ��		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ullong	m_StopFreq;						//��ֹƵ��		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ushort	m_JumpSpeed;					//����			��λ����/�룻���ȣ�0.1��/�룻��Χ��[0,3000] ��/��
	JumpFreq_Parameter_Extend()
	{
		memset(this, 0, sizeof(JumpFreq_Parameter_Extend));
	}
};
//���շ�Ǳ�����źŲ�����չ
struct Aviation_Parameter_Extend
{
	ullong	m_UpFreq;				//����Ƶ��		��λ��Hz�����ȣ�1Hz ����136MHz��173.5MHz
	ullong	m_LowFreq;				//����Ƶ��		��λ��Hz�����ȣ�1Hz ����291.4MHz
	Aviation_Parameter_Extend()
	{
		memset(this, 0, sizeof(Aviation_Parameter_Extend));
	}
};
//΢���źŲ�����չ
struct  Microwave_Parameter_Extend
{
	uchar	m_SingalType;			//�ź�����
	ullong	m_Freq;					//Ƶ��		��λ��Hz�����ȣ�1Hz ΢����Χ��[300000000, 300000000000]Hz ֵ��[300MHz, 300GHz]
	ushort	m_ModelType;			//���Ʒ�ʽ
	Microwave_Parameter_Extend()
	{
		memset(this, 0, sizeof(Microwave_Parameter_Extend));
	}
};

//��������ƻ�����֪ͨ		�����ʶ��A1-20)
struct RRSPlanLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_TaskPlanTitle[100];							//����ƻ�����   �ӵ�һ���ֽڿ�ʼ��䣬������0����ָ���ĵ�ı��⡣
	char   m_TaskPlanID[32];								//����ƻ�ID	 ����ƻ����ı�ʶ
	char   m_ReconObjectNumber[30];						//���Ŀ������
	int     m_AreaLongitude;								//����		ȡֵ��Χ��[-180000000��180000000]����Ӧֵ��[-180��180]��d)	��λ/���ȣ�0.000001�㣻��Чֵ��181000000��˵��������Ϊ��������Ϊ����
	int     m_AreaLatitude;									//γ��		ȡֵ��Χ��[-90000000��90000000]����Ӧֵ��[-90��90]����λ / ���ȣ�0.000001�㣻��Чֵ��91000000��˵������γΪ������γΪ����
	ullong  m_StartFreq;									//�ղ���ʼƵ��		���ȣ�8���ֽڣ���λ�����ȣ� 1Hz����Чֵ��0
	ullong  m_StopFreq;										//�ղ���ֹƵ��		���ȣ�8���ֽڣ���λ�����ȣ� 1Hz����Чֵ��0 ��Ҫ������ղ���ʼƵ��
	char   m_AntennaType[20];								//��������
	ullong  m_RadioFreqMin;									//��ƵƵ����Сֵ	���ȣ�8���ֽڣ���λ�����ȣ� 1Hz����Чֵ��0	
	ullong  m_RadioFreqMax;									//��ƵƵ�����ֵ	���ȣ�8���ֽڣ���λ�����ȣ� 1Hz����Чֵ��0 ��Ҫ�������ƵƵ����Сֵ
	uint	m_PRIMin;										//PRI��Сֵ			ȡֵ��Χ��ֵ��[3300��50000000] ���ȣ�1ns����λ��ns����Ч��0��
	uint    m_PRIMax;										//PRI���ֵ			ȡֵ��Χ��ֵ��[3300��50000000] ���ȣ�1ns����λ��ns����Ч��0��
	uint    m_PulseWidthMin;								//������Сֵ        ��Χ��ֵ��[100��2000000]�����ȣ�1ns����λ��ns����Ч��0��
	uint    m_PulseWidthMax;								//�������ֵ        ��Χ��ֵ��[100��2000000]�����ȣ�1ns����λ��ns����Ч��0��

	RRSPlanLeadNotify()
	{
		memset(this, 0, sizeof(RRSPlanLeadNotify));
		this->m_AreaLongitude = 181000000;
		this->m_AreaLatitude = 91000000;
	}

};

//ͨ������ƻ�����֪ͨ      �����ʶ��A1-30)
struct CRSPlanLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_TaskPlanTitle[100];							//����ƻ�����   �ӵ�һ���ֽڿ�ʼ��䣬������0����ָ���ĵ�ı��⡣
	char   m_TaskPlanID[32];								//����ƻ�ID	 ����ƻ����ı�ʶ
	char   m_ReconObjectNumber[30];						//���Ŀ������
	int     m_AreaLongitude;								//����		ȡֵ��Χ��[-180000000��180000000]����Ӧֵ��[-180��180]��d)	��λ/���ȣ�0.000001�㣻��Чֵ��181000000��˵��������Ϊ��������Ϊ����
	int     m_AreaLatitude;									//γ��		ȡֵ��Χ��[-90000000��90000000]����Ӧֵ��[-90��90]����λ / ���ȣ�0.000001�㣻��Чֵ��91000000��˵������γΪ������γΪ����
	ullong  m_StartFreq;									//�ղ���ʼƵ��		���ȣ�8���ֽڣ���λ�����ȣ� 1Hz����Чֵ��0
	ullong  m_StopFreq;										//�ղ���ֹƵ��		���ȣ�8���ֽڣ���λ�����ȣ� 1Hz����Чֵ��0 ��Ҫ������ղ���ʼƵ��
	char   m_AntennaType[20];								//��������
	char   m_SingalSystem[64];								//�ź�����		��������Ƶ����Ƶ�����ж�����OFDM��PCMA��APCMA��VSAT��DVB-S��DVB-S2������Ƶ��ģ�⻰��Ī��˹
	ullong  m_MidFreq;										//����Ƶ��		���ȣ�8���ֽڣ���λ�����ȣ� 1Hz����Чֵ��0
	uint    m_SingalBandwith;								//�źŴ���      ��Χ:[0,800000000]Hz����λ/���ȣ�1Hz����ЧֵΪ0��
	ushort  m_JumpSpeed;									//����			��λ����/�룻���ȣ�0.1��/�룻��Χ��[0,3000] ��/��
	uchar   m_JumpFreq;										//��ƵƵ�ʼ�����  ��Χ��[1,100]���������1

	CRSPlanLeadNotify()
	{
		memset(this, 0, sizeof(CRSPlanLeadNotify));
	}
};

//IFF����ƻ�����֪ͨ		�����ʶ��A1-40)
struct IFFPlanLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_TaskPlanTitle[100];							//����ƻ�����   �ӵ�һ���ֽڿ�ʼ��䣬������0����ָ���ĵ�ı��⡣
	char   m_TaskPlanID[32];								//����ƻ�ID	 ����ƻ����ı�ʶ
	char   m_ReconObjectNumber[30];						//���Ŀ������
	int     m_AreaLongitude;								//����		ȡֵ��Χ��[-180000000��180000000]����Ӧֵ��[-180��180]��d)	��λ/���ȣ�0.000001�㣻��Чֵ��181000000��˵��������Ϊ��������Ϊ����
	int     m_AreaLatitude;									//γ��		ȡֵ��Χ��[-90000000��90000000]����Ӧֵ��[-90��90]����λ / ���ȣ�0.000001�㣻��Чֵ��91000000��˵������γΪ������γΪ����
	uchar   m_TechnicSystem;								//��������   0=δ֪�� 1 = ��Լ���ƣ�2 = ����˹���ƣ�3 = �����ź����ƣ�255 = �Զ���
	uchar   m_RadioFreq;									//��ƵƵ�ʸ���  ��Χ��[1,100]���������1

	IFFPlanLeadNotify()
	{
		memset(this, 0, sizeof(IFFPlanLeadNotify));
	}
};

//�����������֪ͨ			�����ʶ��A1-50)
struct ReconAreaLeadNotify
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_TaskPlanTitle[100];							//����ƻ�����	 �ӵ�һ���ֽڿ�ʼ��䣬������0����ָ���ĵ�ı��⡣
	char   m_TaskPlanID[32];								//����ƻ�ID	 ����ƻ����ı�ʶ
	char   m_ReconObjectNumber[30];						//���Ŀ������
	int     m_AreaLongitude;								//����		ȡֵ��Χ��[-180000000��180000000]����Ӧֵ��[-180��180]��d)	��λ/���ȣ�0.000001�㣻��Чֵ��181000000��˵��������Ϊ��������Ϊ����
	int     m_AreaLatitude;									//γ��		ȡֵ��Χ��[-90000000��90000000]����Ӧֵ��[-90��90]����λ / ���ȣ�0.000001�㣻��Чֵ��91000000��˵������γΪ������γΪ����
	char   m_ReconObject[100];								//������
	char   m_ReconArea[90];								//�������
	ushort  m_ReconMode;									//֡��ģʽ   1=���⣻2=�ɼ���

	ReconAreaLeadNotify()
	{
		memset(this, 0, sizeof(ReconAreaLeadNotify));
	}
};


//����ִ��״̬�ַ�			�����ʶ��A1-F1)
struct TaskExecuteStateNotify
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	char   m_UnitNumber[10];								//��λ����
	char   m_FightFlag[20];								//�ܴα�ʶ
	char   m_FightName[60];								//�ܴ�����
	char   m_TaskPlanFlag[20];								//����ƻ���ʶ
	char   m_FlatNumber[10];								//ƽ̨���
	char   m_SkyWayFlag[20];								//���߱�ʶ
	char   m_ReconDirectionNumber[3];						//��췽����

	TaskExecuteStateNotify()
	{
		memset(this, 0, sizeof(TaskExecuteStateNotify));
	}

};

//ָ�ӿ�����Ӧ��Ϣ			�����ʶ��A1-FF)
struct ZHContrlInfo_FeedBack
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_FeedBackCode;									//��Ӧ������

	ZHContrlInfo_FeedBack()
	{
		memset(this, 0, sizeof(ZHContrlInfo_FeedBack));
	}
};


#pragma region Эͬ�����Ϣ

// �ڲ�Эͬ����
struct Inside_Coordination_Lead
{
	char m_CommandNumber[commandNumberLength];				//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	quint32 m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	quint8	m_SystemNumber;									//Эͬ��ϵͳ���
	quint8	m_Role;											//��ɫ

	quint8	m_ObjectSystemNumber;							//��Эͬ��ϵͳ���
	quint8   m_ObjectRole;									//��Эͬ��ɫ
	quint16	m_Type;											//Эͬ����	  //BIT0��1����λ��Ϣ��Ч��0����λ��Ϣ��Ч��
																		  //BIT1��1��λ����Ϣ��Ч��0��λ����Ϣ��Ч��
																		  //BIT2��1��Ƶ����Ϣ��Ч��0��Ƶ����Ϣ��Ч��
																		  //BIT3��1��Ŀ����Ϣ��Ч��0��Ŀ����Ϣ��Ч��
																		  //BIT4��1��������Ϣ���ޣ�0��������Ϣ��Ч��

	//Ŀ����Ϣ
	quint8	m_ObjectType;									//Ŀ������
	char	m_ObjectName[90];								//Ŀ������
	char	m_ObjectModel[60];								//Ŀ���ͺ�
	//λ����Ϣ
	qint32	m_Positon_Longitude;							//����λ�þ���
	qint32		m_Position_Latitude;						//����λ��γ��
	//��λ��Ϣ
	qint16	m_Azimuth;										//������λ��	���ȣ� 0.1�㣻��Чֵ�� - 10000����Ӧֵ��[0��360]����ע����Դ�ͷ����
	// ������Ϣ
	char	m_AreaName[90];									// ��������
	char	m_AreaNumber[32];								// ������
	//Ƶ����Ϣ
	quint8	m_SignalType;									//�ź�����
	quint8	m_FreqCounts;									//Ƶ�ʸ���		����Эͬ����ź�����ȷ����ϸ���źŲ�����Ϣ
	
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
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Inside_Coordination_Lead));
	}
};
Q_DECLARE_METATYPE(Inside_Coordination_Lead);		//ע���Զ���ṹ��  ���ź������ʹ��
Q_DECLARE_METATYPE(Msg<Inside_Coordination_Lead>);		//ע���Զ���ṹ��  ���ź������ʹ��

//�ڲ�Эͬ����
struct Inside_Coordination_FeedBack
{
	enum Type
	{
		ICFT_Unknown,		// δ֪
		ICFT_UnExec,		// δִ��
		ICFT_Execing,		// ִ����
		ICFT_Execed,		// ִ�����
		ICFT_ExecPause,		// ִ����ͣ
		ICFT_ExecLetup,		// ִ����ֹ
	};

	char m_CommandNumber[commandNumberLength];				//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	quint32 m_Time;											//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	quint8	m_SystemNumber;									//�����ķ�ϵͳ���
	quint8	m_Role;											//�����Ľ�ɫ
	char	m_RecordFlag[20];								//������¼��ʶ	���ݿ��м�¼����Ӧ�鱨��������Ϣ��Ψһ��ʶ
	quint8	m_CoordinationFeedBack;							//Эͬ�������	0=��Ч��1 = δִ��(����֪ͨ5���δִ�����Զ�������״̬)��2 = ִ���У� 3 = ִ����ɣ�4 = ִ����ͣ(�˹���ͣ���Զ���ִͣ�����Զ��ϱ���״̬)��5 = ִ����ֹ(�˹���ֹ���ϱ���״̬)��
	quint16	m_TextLength;									//˵�����ĳ���	0ʱ����˵�������ֶΣ���Χ0-2000

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
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Inside_Coordination_FeedBack));
	}
};
Q_DECLARE_METATYPE(Inside_Coordination_FeedBack);		//ע���Զ���ṹ��  ���ź������ʹ��
Q_DECLARE_METATYPE(Msg<Inside_Coordination_FeedBack>);		//ע���Զ���ṹ��  ���ź������ʹ��

//�ⲿЭͬ����֪ͨ
struct Out_Coop_Notify
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;										//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	uchar	m_CoordinationType;							//Эͬ����		0-��Ч��1 - ˫��Эͬ��λ(�ɻ�����Эͬ��������λ��˫����ͨ����)��
														//				2 - �յ�Эͬ����(��������Эͬ�Ͷ�λ��˫�����ڹ�����)��
	
	Out_Coop_Notify()
	{
		memset(this, 0, sizeof(Out_Coop_Notify));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Out_Coop_Notify));
	}
};

//�ⲿЭͬ����֪ͨ����
struct Out_Coop_Notify_Feedback
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint    m_Time;										//ʱ��		     Ϊ���1970��1��1��0ʱ0��0�����ƫ����
	uchar	m_CoordinationType;							//Эͬ����		0-��Ч��1 - ˫��Эͬ��λ(�ɻ�����Эͬ��������λ��˫����ͨ����)��
														//				2 - �յ�Эͬ����(��������Эͬ�Ͷ�λ��˫�����ڹ�����)��
	ushort  m_ExecuteState;								//ִ��״̬		0=��Ч��1 = δִ��(����֪ͨ5���δִ�����Զ�������״̬)��2 = ִ���У�3 = ִ����ɣ�4 = ִ����ͣ(�˹���ͣ���Զ���ִͣ�����Զ��ϱ���״̬)��5 = ִ����ֹ(�˹���ֹ���ϱ���״̬)

	Out_Coop_Notify_Feedback()
	{
		memset(this, 0, sizeof(Out_Coop_Notify_Feedback));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Out_Coop_Notify_Feedback));
	}
};

Q_DECLARE_METATYPE(Out_Coop_Notify_Feedback);

//�ⲿЭͬ�źŲ���
struct Outside_Coordination_SingalParameter
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//����ͨ�Ŵ�������
	uint	m_SendPlatformNumber;							//����ƽ̨���	JIDS��905������ͨ��ƽ̨�ţ���Ч��0
	uint	m_ReceivePlatformNumber;						//����ƽ̨���  
	uint	m_Coordination_StartTime;						//Эͬ��ʼʱ��
	uchar	m_Coordination_KeepTime;						//Эͬפ��ʱ��	��λ/���ȣ�1s����Χ��[0,1000],Ϊ0����ʱ������
	uchar	m_ReconType;									//����ֶ�����
	uchar	m_Location_Contrl;								//��λ����0=��Ч��1 = ��ʼЭͬ��죻2 = ֹͣЭͬ��죻
	uchar	m_Coordination_Type;							//Эͬ����		0-��Ч��1 - ˫��Эͬ��λ(�ɻ�����Эͬ)��2 - ˫��Эͬ����(��������Эͬ)��
	int		m_ReconAreaLongitude;							//������򾭶�
	int     m_ReconAreaLatitude;							//�������γ��
	uchar	m_SingalParameterFlag;							//�źŲ�����־	0=��Ч; 1 = ���źŲ���(������ֹͣ)��2 = ���źŲ���(�ʺ�������)��
	uchar	m_CoopSigNum;									//Эͬ�źŸ���N	NС�ڵ���3

	Outside_Coordination_SingalParameter()
	{
		memset(this, 0, sizeof(Outside_Coordination_SingalParameter));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Outside_Coordination_SingalParameter));
	}

};
//����Эͬ�źŲ���  (Ϊ�ⲿЭͬ�źŲ���������)
struct Coordination_SingalParameter
{
	uchar	m_SingalType;								//�ź�����
	ushort	m_ParameterNumber;							//Эͬ�������	�������ķ���ϵͳ������ź�/����Դ��Ż��ߵ������(����ϵͳʹ��)��
	//���뱣֤��Ψһ�ԣ������ź����ͷֱ��ţ���1��ʼ���������1ѭ�����
	ushort	m_ParameterFlag;							//�źŲ�����ʶ	��λ��ʾ����λȡֵΪ1ʱ��ʾ�߱����ź�Эͬ����źŲ�������λΪ0ʱ��ʾ�����ڴ��ź�������չ���ġ�
	Coordination_SingalParameter()
	{
		memset(this, 0, sizeof(Coordination_SingalParameter));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Coordination_SingalParameter));
	}
};
//�ⲿЭͬ�źŲ�������
struct Outside_Coordination_SingalParameterFeedBack
{
	char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//����ͨ�Ŵ�������
	uint	m_SendPlatformNumber;						//����ƽ̨���	�ۺ���ƽ̨ID
	uint	m_ReceivePlatformNumber;					//����ƽ̨���
	uint	m_CoordinationStartTime;					//Эͬ��ʼʱ��
	uchar	m_ReconType;								//����ֶ�����
	uchar	m_SingalType;								//�ź�����
	uint	m_CoordinationParameterCode;				//Эͬ�������	��Эͬ�����е�Эͬ���һ�»�����Ĳ������һ�£���������Ϊ0ʱ��0��
	uchar	m_LocationContrlFlag;						//��λ����״̬	0=��Ч��1 = ��ʼЭͬ��죻2 = ֹͣЭͬ��죻
	uchar	m_CoordinationFBType;						//Эͬ��������	0=��Ч��1 = Эͬ�ɹ���2 = Эͬʧ�ܣ�255 = ��������
	char	m_Text[30];									//����			�������ĳ��Ƚ���ȷ��

	Outside_Coordination_SingalParameterFeedBack()
	{
		memset(this, 0, sizeof(Outside_Coordination_SingalParameterFeedBack));
	}

};
//�ⲿЭͬ��������
struct Outside_Coordination_TestData
{
	char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//����ͨ�Ŵ�������
	uint	m_SendPlatformNumber;						//����ƽ̨���	JIDS��905������ͨ��ƽ̨�ţ���Ч��0
	uint	m_ReceivePlatformNumber;					//����ƽ̨���
	uchar	m_SystemNumber;								//��ϵͳ���
	uchar	m_SingalType;								//�ź�����
	uint	m_CoordinationParameterCode;				//Эͬ�������
	ullong	m_TestTime;									//����ʱ��
	ushort	m_IndicationDegree;							//ʾ���		��λ������Чֵ��3610 ��Ӧֵ��[0��360] ��ע���˷�λ������Ϊ��ȣ�˳ʱ�뷽��Ϊ��
	int		m_Longitude;								//ƽ̨����		ȡֵ��Χ��[-180000000��180000000]����Ӧֵ��[-180��180]��d)	��λ/���ȣ�0.000001�㣻��Чֵ��181000000��˵��������Ϊ��������Ϊ����
	int		m_Latitude;									//ƽ̨γ��		ȡֵ��Χ��[-90000000��90000000]����Ӧֵ��[-90��90]����λ / ���ȣ�0.000001�㣻��Чֵ��91000000��˵������γΪ������γΪ����
	int		m_High;										//ƽ̨�߶�
	uchar	m_ParameterSign;							//�źŲ�����־	0=��Ч 1 = ���źŲ���(������˫��Эͬ��λ)��2 = ���źŲ���(�����ڿտ� / �յ�Эͬ����������ϱ���������ʱ)��
	ushort	m_ParameterFlag;							//�źŲ�����ʶ
	Outside_Coordination_TestData()
	{
		memset(this, 0, sizeof(Outside_Coordination_TestData));
		this->m_IndicationDegree = 3610;
		this->m_Longitude = 181000000;
		this->m_Latitude = 91000000;
	}
};
//Эͬ��Ӧ��Ϣ
struct Coordination_FeedBack
{
	char m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	uint	m_FeedBackCode;									//��Ӧ������
	Coordination_FeedBack()
	{
		memset(this, 0, sizeof(Coordination_FeedBack));
	}
};
#pragma endregion

#pragma region ����ͨ����Ϣ
// �ļ�����֪ͨ
struct FileTransmitNotice
{
	enum ControlType
	{
		Start = 1,
		Stop = 2,
	};

	char	m_CommandNumber[commandNumberLength];			//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	quint16	m_subSystemNumber;								// ���ͷ�ϵͳ���
	quint32	m_sendPlatNumber;								// ����ƽ̨���
	quint32 m_receivePlatNumber;							// ����ƽ̨���
	quint8	m_controlType;									// ������ͣ, 0=��Ч��	1 = ��ʼ���䣻2 = ֹͣ���䣻
	char	m_filePath[256];								// �ļ�·����FTP·��
	char	m_fileName[256];								// �����ļ���
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


// �ļ�����֪ͨ����
struct FileTransmitNoticeFeedback
{
	enum FeedbackState
	{
		Unvaild		= 0,	// ��Ч
		NotExecute	= 1,	// δִ��
		Executing	= 2,	// ִ����
		Finished	= 3,	// ִ�����
		Pause		= 4,	// ִ����ͣ
		Stop		= 5,	// ִ����ֹ
	};

	char	m_CommandNumber[commandNumberLength];			// �����ţ�������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ����ļ�����֪ͨ��������
	quint32	m_time;											// ʱ��
	quint16	m_subSystemNumber;								// ����ƽ̨���
	quint16 m_feedbackState;								// ����ƽ̨���
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

// �ļ�����״̬
struct FileTransmitState
{
	enum State
	{
		Unvaild		= 0,	// ��Ч
		Transmit	= 1,	// ����״̬
		Wait		= 2,	// �ȴ�״̬
		Stop		= 3,	// ֹͣ״̬
		Finished	= 4,	// ���״̬
		Fault		= 5,	// ����״̬
	};

	char	m_CommandNumber[commandNumberLength];	// �����ţ�������Ϣ+��YYYYMMDDHHNNSS��+��ˮ�ţ����ļ�����֪ͨ��������
	char	m_fileName[256];						// �ļ����ƣ�����������
	quint8	m_state;								// ����״̬  0-��Ч��1-����״̬��2-�ȴ�״̬��3-ֹͣ״̬��4-���״̬��5-����״̬������ֵ��Ч
	quint32 m_progress;								// �������  [0,10000],��λ%�����ȣ�0.01% ��Χ:[0, 100], ����ֵ��Ч��ȱʡΪ0
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

//����������ͷ
struct DataLink_Header
{
	char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	ushort	m_DataLinkType;								//����������	0=��Ч��1=JIDS����2=905����3=��ͨ��·

	DataLink_Header()
	{
		memset(this, 0, sizeof(DataLink_Header));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Header));
	}
};

//������Эͬ��������
struct DataLink_TaskRequest
{
	//char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//ushort	m_DataLinkType;								//����������	0=��Ч��1=JIDS����2=905����3=��ͨ��·
	////����ͨ�Ŵ�������
	////4908��ͷ������   ��ʱʹ��charռ��λ��
	//char	m_Report[46];

	uint	m_SendPlatform;								//����ƽ̨��Ա	����������Ա��Ϣ�ַ��е������Աƽ̨��
	uint	m_ReceivePlatform;							//����ƽ̨��Ա
	uchar	m_CoordinationType;							//Эͬ����		0-��Ч��1 - ˫��Эͬ��λ(�ɻ�����Эͬ��������λ��˫����ͨ����)��
	//				2 - �յ�Эͬ����(��������Эͬ�Ͷ�λ��˫�����ڹ�����)��
	uchar	m_CoordinationContrl;						//Эͬ����		0-��Ч��1-������2-ȡ����
	ushort	m_RequestNumber;							//������ˮ��	��1��ʼ��ţ�[1,65535],����65535����1������ţ��ɿ��л�����������������������ά����
	//				����Эͬ���ͷֱ��ţ��������±��
	uchar	m_TextLength;								//���ĳ���		Эͬ�������ĵĳ���������[0,60],Ϊ0ʱ�ޡ�Эͬ�������ġ��ֶ�
	//uchar	m_Text[N];									//Эͬ��������
	DataLink_TaskRequest()
	{
		memset(this, 0, sizeof(DataLink_TaskRequest));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_TaskRequest));
	}
};
//������Эͬ����������
struct DataLink_TaskRequest_FeedBack
{
	//char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//ushort	m_DataLinkType;								//����������	0=��Ч��1=JIDS����2=905����3=��ͨ��·
	////����ͨ�Ŵ�������
	////4908��ͷ������   ��ʱʹ��charռ��λ��
	//char	m_Report[46];

	uint	m_SendPlatform;						//����ƽ̨���	����������Ա��Ϣ�ַ��е������Աƽ̨��
	uint	m_ReceivePlatform;					//����ƽ̨���
	ushort	m_RequestNumber;							//������ˮ��	��Эͬ�����е�Эͬ���һ�£���������Ϊ0ʱ��0��
	uchar	m_CoordinationResult;						//Эͬ���		0-��Ч��1-ͬ�⣻2-�ܾ��� 
	uchar	m_TextLength;								//���ĳ���		�����������ĵĳ���������[0,60],Ϊ0ʱ�ޡ��������ġ��ֶ�
	//uchar	m_Text[N];									//����
	DataLink_TaskRequest_FeedBack()
	{
		memset(this, 0, sizeof(DataLink_TaskRequest_FeedBack));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_TaskRequest_FeedBack));
	}
};
//������Эͬ�źŲ���
struct DataLink_Parameter
{
	//char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//ushort	m_DataLinkType;								//����������	0=��Ч��1=JIDS����2=905����3=��ͨ��·
	////����ͨ�Ŵ�������
	////4908��ͷ������   ��ʱʹ��charռ��λ��
	//char	m_Report[46];

	uint	m_SendPlatformNumber;						//����ƽ̨���	JIDS��905������Ч��0
	uint	m_ReceivePlatformNumber;					//����ƽ̨���	JIDS��905������Ч��0
	uchar	m_ReconType;								//����ֶ�����
	uchar	m_SingalType;								//�ź�����
	uint	m_CoordinationParameter;					//Эͬ�������	�������ķ���ϵͳ������ź�/����Դ��Ż��ߵ������(����ϵͳʹ��)��
														//				���뱣֤��Ψһ�ԣ������ź����ͷֱ��ţ���1��ʼ���������1ѭ�����
	uchar	m_LocationContrl;							//��λ����		0=��Ч��1 = ��ʼЭͬ��죻2 = ֹͣЭͬ��죻
	uchar	m_CoordinationType;							//Эͬ����		0-��Ч��1 - ˫��Эͬ��λ(�ɻ�����Эͬ)��2 - ˫��Эͬ����(��������Эͬ)��
	int		m_ReconLongitude;							//������򾭶�
	int		m_ReconLatitude;							//�������γ��	
	uchar	m_SingalParaFlag;							//�źŲ�����־	0=��Ч 1 = ���źŲ���(�����ڿ�ʼЭͬ���)��2 = ���źŲ���(������ֹͣЭͬ���)��
	uchar	m_Save;										//�����ֶ�
	DataLink_Parameter()
	{
		memset(this, 0, sizeof(DataLink_Parameter));
	}
};
//������Эͬ�źŲ�������
struct DataLink_Parameter_FeedBack
{
	//char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//ushort	m_DataLinkType;								//����������	0=��Ч��1=JIDS����2=905����3=��ͨ��·
	////����ͨ�Ŵ�������
	////4908��ͷ������   ��ʱʹ��charռ��λ��
	//char	m_Report[46];

	uint	m_SendPlatformNumber;						//����ƽ̨���	JIDS��905������Ч��0
	uint	m_ReceivePlatformNumber;					//����ƽ̨���	JIDS��905������Ч��0
	uchar	m_ReconType;								//����ֶ�����
	uchar	m_SingalType;								//�ź�����
	uint	m_CoordinationParameter;					//Эͬ�������	��Эͬ�����е�Эͬ���һ�»�����Ĳ������һ�£���������Ϊ0ʱ��0��
	
	uchar	m_LocationContrl;							//��λ����״̬	0=��Ч��1 = ��ʼЭͬ��죻2 = ֹͣЭͬ��죻
	uchar	m_CoordinationFBType;						//Эͬ��������	0=��Ч��1 = Эͬ�ɹ���2 = Эͬʧ�ܣ�255 = ��������
	uchar	m_TextLength;								//���ĳ���
	//uchar m_Text[N];									//����
	DataLink_Parameter_FeedBack()
	{
		memset(this, 0, sizeof(DataLink_Parameter_FeedBack));
	}
};
//������Эͬ��������
struct DataLink_DirFindData
{
	//char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	//ushort	m_DataLinkType;								//����������	0=��Ч��1=JIDS����2=905����3=��ͨ��·
	////����ͨ�Ŵ�������
	////4908��ͷ������   
	//char	m_Report[46];	//��ʱʹ��charռ��λ��

	uint	m_SendPlatformNumber;						//����ƽ̨���	JIDS��905������Ч��0
	uint	m_ReceivePlatformNumber;					//����ƽ̨���	JIDS��905������Ч��0
	ushort	m_IntentionID;								//Ŀ���߼�ID	��Ϣ���յ��߼�ID(�տ�/�յ�Эͬ����ʱ�����ֶ���Ч)
	uchar	m_SystemNumber;								//��ϵͳ���
	uchar	m_SingalType;								//�ź�����
	uint	m_CoordinationNumber;						//Эͬ�������	���Эͬ�����еĲ������
	ullong	m_TestTime;									//����ʱ��
	ushort	m_IndecationDegree;							//ʾ���		ȡֵ��Χ��[0��3600] ��λ���� ��Чֵ��3610
														//				��Ӧֵ��[0��360] ��ע���˷�λ������Ϊ��ȣ�˳ʱ�뷽��Ϊ��
	uchar	m_IndecationBelive;							//ʾ������Ŷ�	[0,100]%
	int		m_PlatformLongitude;						//ƽ̨����
	int		m_PlatformLatitude;							//ƽ̨γ��
	int		m_PlatformHigh;								//ƽ̨�߶�
	uchar	m_SingalParameterSign;						//�źŲ�����ʶ	0=��Ч 1 = ���źŲ���(������˫��Эͬ��λ)��
														//				2 = ���źŲ���(�����ڿտ� / �յ�Эͬ����������ϱ���������ʱ)��
	ushort	m_SingalParameterFlag;						//�źŲ�����ʶ
	DataLink_DirFindData()
	{
		memset(this, 0, sizeof(DataLink_DirFindData));
	}
};
//��������Ա��Ϣ�ַ�
struct DataLink_Distribute
{
	char m_CommandNumber[commandNumberLength];		//������		 ������Ϣ+��YYYYMMDDHHNNSS��+��ˮ��;
	ushort	m_Counts;									//��������Ա����
	//��������Ա��Ϣ

	DataLink_Distribute()
	{
		memset(this, 0, sizeof(DataLink_Distribute));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Distribute));
	}
};
//������������Ա��Ϣ��������������Ա��Ϣ�ַ��У�
struct DataLink_Single
{
	char	m_Name[recordFlag];							//��������Ա����
	ushort	m_Type;							//��������Ա����	0=��Ч��1=JIDS����2=905����3=��ͨ��·
	uchar	m_PlatformFlag;					//ƽ̨��ʶ			0-��ƽ̨��1-����ƽ̨
	uint	m_PlatformNumber;				//������ƽ̨��		JIDS��905������ͨ��ƽ̨�ţ���Ч��0
	DataLink_Single()
	{
		memset(this, 0, sizeof(DataLink_Single));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Distribute));
	}
};
#pragma endregion 

/*								Эͬ�����չ�ֶ�								*/
//���̲��ź�Эͬ����źŲ���
struct Ultrashort_Coordination_Extend
{
	ullong	m_Freq;					//Ƶ��		���ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ushort	m_ModelType;			//���Ʒ�ʽ
	uint	m_SymbolSpeed;			//��������	��λSPS
	Ultrashort_Coordination_Extend()
	{
		memset(this, 0, sizeof(Ultrashort_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Ultrashort_Coordination_Extend));
	}
};
//�����ź�Эͬ����źŲ���
struct Satellite_Coordination_Extend
{
	ullong	m_UpFreq;					//����Ƶ��	ȡֵ��Χ��[30000000��3000000000]����λ��Hz�����ȣ�1 Hz����Чֵ��0��
	ullong	m_ModelSpeed;				//��������	��λ������
	ushort	m_ModelType;				//���Ʒ�ʽ
	Satellite_Coordination_Extend()
	{
		memset(this, 0, sizeof(Satellite_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Satellite_Coordination_Extend));
	}
};
//�״��ź�Эͬ����źŲ���
struct Radar_Coordination_Extend
{
	uchar	m_RadioFreqType;					//��Ƶ����
	int		m_RadioFreqStandard;				//��Ƶ���ֵ	��λ/���ȣ�1kHz����Χ��[500000,40000000]kHz����Чֵ0
	int		m_RadioFreqMin;						//��Ƶ��Сֵ
	int		m_RadioFreqMax;						//��Ƶ���ֵ
	int		m_RadioFreqValue1;					//��Ƶȡֵ1
	int		m_RadioFreqValue2;					//��Ƶȡֵ2
	int		m_RadioFreqValue3;					//��Ƶȡֵ3
	
	ushort	m_RepeatIntervalType;				//�ظ��������
	uint	m_RepeatIntervalStandard;			//�ظ�������ֵ	��λ/���ȣ�1ns����Чֵ0; ȡֵ��Χ��[660��10000000]��
	uint	m_RepeatIntervalUp;					//�ظ��������ֵ	
	uint	m_RepeatIntervalLow;				//�ظ��������ֵ
	uint	m_RepeatIntervalValue1;				//�ظ����ȡֵ1
	uint	m_RepeatIntervalValue2;				//�ظ����ȡֵ2
	uint	m_RepeatIntervalValue3;				//�ظ����ȡֵ3

	ushort	m_PulseType;						//��������
	uint	m_PulseStandard;					//������ֵ		��λ/���ȣ�1ns����Χ��[20��400000]
	uint	m_PulseUp;							//��������ֵ
	uint	m_PulseLow;							//��������ֵ
	Radar_Coordination_Extend()
	{
		memset(this, 0, sizeof(Radar_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Radar_Coordination_Extend));
	}
};
//����IFF�ź�Эͬ����źŲ���
struct AmericalIFF_Coordination_Extend
{
	uchar	m_ModelNumber;					//ģʽ����
	uint	m_AirplanAddress;				//�ɻ���ַ	Ӧ��ģʽ�Ľ���BCD���룬(0001-7777),�����еķɻ�����һ��ȷ���Ͳ���仯 ��Ϊѯ�ʼ�Ӧ��ģʽS�Ĺ�������
	uint	m_CodeInfo;						//������Ϣ	��Чֵ��0xFFFF FFFF ��Ϊ��ͨӦ��Ĺ�������
	char	m_Save[6];						//����		��������
	AmericalIFF_Coordination_Extend()
	{
		memset(this, 0, sizeof(AmericalIFF_Coordination_Extend));
		this->m_CodeInfo = 0xFFFF;
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(AmericalIFF_Coordination_Extend));
	}
};
//����IFF�ź�Эͬ����źŲ���
struct RussiaIFF_Coordination_Extend
{
	uchar	m_ModelNumber;				//ģʽ����
	uint	m_Airplancode;				//�ɻ�����	����BCD���룬(0001-7777),�����еķɻ�����һ��ȷ���Ͳ���仯 ��Ϊ����IFFӦ���źŵĹ�������
	ullong	m_Freq;						//Ƶ��	��λ��Hz�����ȣ�1Hz ��Χ:[650000000, 2700000000]Hz
	ushort	m_Save;						//�����ֶ�	�����ֶΣ�ȫ0
	RussiaIFF_Coordination_Extend()
	{
		memset(this, 0, sizeof(RussiaIFF_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(RussiaIFF_Coordination_Extend));
	}
};
//�����ź�Эͬ����źŲ���
struct Navigation_Coordination_Extend
{
	ullong	m_RadioFreq;					//��ƵƵ��	��λ��Hz�����ȣ�1Hz ��Χ:[962000000, 1213000000]Hz
	uchar	m_TACANModel;					//TACAN����ģʽ		��Χ��[0,255]����¼A��TACAN/DME����ģʽ
	char	m_DistinguishCode[30];				//̨վʶ����
	Navigation_Coordination_Extend()
	{
		memset(this, 0, sizeof(Navigation_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Navigation_Coordination_Extend));
	}
};
//�����������ź�Эͬ����źŲ���
struct DataLink_Coordination_Extend
{
	ullong	m_Freq;						//Ƶ��	��λ��Hz�����ȣ�1Hz �̲���Χ:[1500000, 30000000]Hz ���̲���Χ��[30000000, 3000000000]Hz
	ushort	m_ModelType;				//���Ʒ�ʽ
	ushort	m_Address;					//�����ַ	����PU��
	DataLink_Coordination_Extend()
	{
		memset(this, 0, sizeof(DataLink_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(DataLink_Coordination_Extend));
	}
};
//��Ƶ�ź�Эͬ����źŲ���
struct JumpFreq_Coordination_Extend
{
	ushort	m_NetWorkNumber;			//��̨��
	ullong	m_StartFreq;				//��ʼƵ��		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ullong	m_StopFreq;					//��ֹƵ��		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ushort	m_JumpSpeed;				//����			��λ����/�룻���ȣ�0.1��/�룻��Χ��[0,3000] ��/��
	uint	m_JumpFreqPeriod;			//��Ƶ����		��λ��us�����ȣ�1us����Χ��[0,500000]us 
	uint	m_KeepTime;					//פ��ʱ��		��λ��us�����ȣ�1us����Χ��[0,500000]us
	ullong	m_JumpFreq1;				//��ƵƵ��1		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ullong	m_JumpFreq2;				//��ƵƵ��2		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ullong	m_JumpFreq3;				//��ƵƵ��3		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ullong	m_JumpFreq4;				//��ƵƵ��4		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz
	ullong	m_JumpFreq5;				//��ƵƵ��5		��λ��Hz�����ȣ�1Hz ��Χ��[30000000, 3000000000]Hz

	JumpFreq_Coordination_Extend()
	{
		memset(this, 0, sizeof(JumpFreq_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(JumpFreq_Coordination_Extend));
	}
};
//Link16�ź�Эͬ����źŲ���
struct Link16_Coordination_Extend
{
	uint	m_RadiationNumber;				//����Դ���
	Link16_Coordination_Extend()
	{
		memset(this, 0, sizeof(Link16_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Link16_Coordination_Extend));
	}
};
//���շ�Ǳ�����ź�Эͬ����źŲ���
struct Aviation_Coordination_Extend
{
	ullong	m_UpFreq;						//����Ƶ��		��λ��Hz�����ȣ�1Hz ����136MHz��173.5MHz
	ullong	m_LowFreq;						//����Ƶ��		��λ��Hz�����ȣ�1Hz ����291.4MHz
	Aviation_Coordination_Extend()
	{
		memset(this, 0, sizeof(Aviation_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Aviation_Coordination_Extend));
	}
};
//΢���ź�д������
struct Microwave_Coordination_Extend
{
	ullong	m_Freq;					//Ƶ��		��λ��Hz�����ȣ�1Hz ΢����Χ��[300000000, 300000000000]Hz ֵ��[300MHz, 300GHz]
	ushort	m_ModelType;			//���Ʒ�ʽ
	uint	m_SymbolSpeed;			//��������	��λ��SPS
	Microwave_Coordination_Extend()
	{
		memset(this, 0, sizeof(Microwave_Coordination_Extend));
	}
	//��buf�ж�ȡ����
	void DataFromBuf(char* buf)
	{
		memcpy(this, buf, sizeof(Microwave_Coordination_Extend));
	}
};

#pragma pack(pop)

#endif //MSGDEFINE_H