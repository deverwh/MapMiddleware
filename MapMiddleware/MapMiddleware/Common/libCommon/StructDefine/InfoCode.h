#pragma once

//��Ϣ�����

//��Ϣ��𳤶�
#define INFOCODELEN		2
//��Ϣ���೤��
#define SUBCODELEN		2
//16����
#define HEXADECIMAL		16
//10����
#define DECIMAL			10
//��ˮ�ų���
#define FLOWCODELEN		3

enum InfoCode
{
	Command_Control = 0xA1,			// ָ�ӿ�����Ϣ
	System_Monitor = 0xA2,			// ϵͳ�����Ϣ
	Instrument_Sense = 0xA3,		// �ֶ������Ϣ
	Intelligence_Dispose = 0xA4,	// �鱨������Ϣ
	Cooperate_Scout = 0xA5,			// Эͬ�����Ϣ
	Reorganize_Guide = 0xA6,		// ����������Ϣ
	Task_Comminucate = 0xA7,		// ����ͨ����Ϣ
	System_Currency = 0xA8,			// ϵͳͨ����Ϣ
	Resource_Manager = 0xA9,		// ��Դ������Ϣ
	Sound_Distinguish = 0xB0,		// ����ʶ����Ϣ
	Situation_Mutual = 0xC0,		// ̬�ƽ�����Ϣ
	Collect_Manager = 0xD0,			// �ɼ�������Ϣ
	Immediately_Mutual = 0xE0		// ��ʱͨ������Ϣ
};

//ָ�ӿ�����Ϣ_��Ϣ���ඨ��
enum CommandCtrl_SubInfoCode
{
	CommandNoticeDispatch = 0x01,			// ָ���ĵ�֪ͨ�ַ�
	CommandNoticeFeedback = 0x02,			// ָ���ĵ�֪ͨ����
	TaskPlanNoticeDispatch = 0x03,			// ����ƻ�֪ͨ�ַ�
	TaskPlanNoticeFeedback = 0x04,			// ����ƻ�֪ͨ����
	CCT_FileTransRequest = 0x05,			// �ļ�������������
	CCT_FileTransFeedback = 0x06,			// �ļ�������������
	SupportIntelliNoticeDispatch = 0x07,	// ֧Ԯ�鱨֪ͨ�ַ�
	RRSPlanLeadNotice = 0x20,				// ��������ƻ�����֪ͨ
	CRSPlanLeadNotice = 0x30,				// ͨ������ƻ�����֪ͨ
	IFFPlanLeadNotice = 0x40,				// IFF����ƻ�����֪ͨ
	ReconAreaLeadNotice = 0x50,				// �����������֪ͨ
	ArtificePlanExecFeedback = 0xF0,		// �ֶ�����ƻ�ִ�з���
	TaskExecuteStateDispatch = 0xF1,		// ����ִ��״̬�ַ�
	CommandCtrlFeedback = 0xFF				// ָ�ӿ�����Ӧ��Ϣ
};


//�鱨������Ϣ_��Ϣ���ඨ��
enum IntelliDispose_SubInfoCode
{
	IntelliMaterialReport = 0x01,			// �鱨�ز��ϱ�֪ͨ
	ColligIntelliReport = 0x02,				// �ۺ��鱨�ϱ�
	ColligIntelliFeedback = 0x03,			// �ۺ��鱨�ϱ�����
	ColligSituationDispatch = 0x04,			// �ۺ�̬����Ϣ�ַ�
	ExternPlatPosDispatch = 0x05,			// ��ƽ̨λ�÷ַ�
	ExternPlatSituationDispatch = 0x06,		// ��ƽ̨̬�Ʒַ�
	ExternPlatSituationDiffReport = 0x07,	// ��ƽ̨̬����֤���챨��
	DataLinkDataUpdate = 0x08,				// ���������ݸ�������
	IntelliDisposeFeedback = 0xFF			// �鱨������Ӧ��Ϣ
};

//Эͬ�����Ϣ_��Ϣ���ඨ��
enum CooperateScout_SubInfoCode
{
	InnerCoopLead = 0x01,					// �ڲ�Эͬ����
	InnerCoopFeedback = 0x02,				// �ڲ�Эͬ����
	ExterCoopTaskNotify = 0x03,				// �ⲿЭͬ����֪ͨ
	ExterCoopTaskNotifyFeedback = 0x04,		// �ⲿЭͬ����֪ͨ����
	ExterCoopSignalParam = 0x10,			// �ⲿЭͬ�źŲ���
	ExterCoopSignalParamFeedback = 0x11,	// �ⲿЭͬ�źŲ�������
	ExterCoopDirFindData = 0x12,			// �ⲿЭͬ��������
	CooperateScoutFeedback = 0xFF			// Эͬ��Ӧ��Ϣ
};


//����ͨ����Ϣ_��Ϣ���ඨ��
enum TaskComm_SubInfoCode
{
	CommandNotice = 0x01,					// ָ���ĵ�֪ͨ
	FileTransNotice = 0x02,					// �ļ�����֪ͨ
	TCT_FileTransFeedback = 0x03,			// �ļ�����֪ͨ����
	FileTransState = 0x04,					// �ļ�����״̬
	ColligSituationTsData = 0x05,			// �ۺ�̬�ƴ�������
	AirplanePosTsData = 0x06,				// �ػ�λ�ô�������
	SystemStateTsData = 0x07,				// ϵͳ״̬��������
	DataLinkRecvData = 0x08,				// ��������������
	DataLinkIDTable = 0x09,					// ���������Ŷ��ձ�
	DataLinkCoopTaskRequest = 0x0A,			// ������Эͬ��������
	DataLinkCoopTaskFeedback = 0x0B,		// ������Эͬ����������
	DataLinkCoopSignalParam = 0x0C,			// ������Эͬ�źŲ���
	DataLinkCoopSignalParamFeedback = 0x0D,	// ������Эͬ�źŲ�������
	DataLinkCoopDirFindData = 0x0E,			// ������Эͬ��������
	DataLinkMemberInfoDispatch = 0x0F,		// ��������Ա��Ϣ�ַ�
	TaskCommFeedback = 0xFF					// ����ͨ����Ӧ��Ϣ
};

//�ɼ�������Ϣ_��Ϣ���ඨ��
enum CollectManager_SubInfoCode
{
	TrainDataCollectNotice = 0x01,			// ѵ�����ݲɼ�֪ͨ
	CollectCtrlLeadCmd = 0x02,				// �ɼ���������ָ��
	CollectStateReport = 0x03,				// �ɼ�״̬�ϱ�
	CollectCtrlFeedback = 0xFF				// �ɼ�������Ӧ��Ϣ
};

//����������
 enum EDataLinkType
 {
	 DLT_Invalid = 0,	//��Ч
	 DLT_JIDS,			//JIDS
	 DLT_Link905,		//905��
	 DLT_SateCom		//��ͨ��·
 };

 //Эͬ����
 enum ECoopType
 {
	 CT_Invalid = 0,			//��Ч
	 CT_DoublePlanCoop,			//˫��Эͬ��λ
	 CT_SkyLandCoop			//�յ�Эͬ����
 };

//Эͬ��������
 enum ECoopCtrlType
 {
	 CCT_Invalid = 0,		//��Ч
	 CCT_Create,			//����
	 CCT_Delete			//ȡ��
 };

 //Эͬ���
 enum ECoopResultType
 {
	 CRT_Invalid = 0,		//��Ч
	 CRT_Agree,				//ͬ��
	 CRT_Reject			//�ܾ�
 };

 //���ӻ���ɫ
 enum EPlaneRoleType
 {
	 PRT_Invalid = 0,	//��Ч
	 PRT_Master,		//����
	 PRT_Deputy		//�ӻ�
 };

 //Эͬ״̬
 enum ECoopStatusType
 {
	 CST_Invalid = 0,	//��Ч
	 CST_NoCoop,		//δЭͬ
	 CST_Cooping		//Эͬ��
 };

 //�ź�����
 enum ESignalType
 {
	 T_Unknown = 0,//δ֪
	 RadarSig = 1,//�״��ź�
	 SW = 2,//�̲�
	 SSW = 3,//���̲�
	 MicroWave = 4,//΢��
	 Report = 5,   //����
	 MissileRemote = 6, //����ң��
	 HopFreq = 7,//��Ƶ
	 SpreadFreq = 8,     //��Ƶ
	 Link16 = 9,//Link16
	 TACAN = 10,//����
	 AIS = 11,//AIS
	 ACARS = 12,//ACARS
	 ADS_B = 13,//ADS-B
	 IFF = 14,//IFF 
	 IFF_US = 141,//����IFF 
	 IFF_RUS = 142,//����IFF
	 IFFQue_US = 143,//����IFFѯ��
	 IFFRes_US = 144,//����IFFӦ�� 
	 Gen_DataLink = 15,//�����������ź�
	 Link11 = 151,//Link11�������ź�
	 Link4A = 152,//Link4A�������ź�
	 link14 = 153,//Link14�������ź�
	 Universal_Satellite = 16,//�����ź�		
	 Sea_Third_Satellite = 161,//�������������ź�		
	 Sea_Forth_Satellite = 162,//�����Ĵ������ź�		
	 MaritimeIridium = 163,//ҿ�������ź�		
	 NStar = 164,//NStar		
	 MSS = 165,//MSS		
	 Tactics_Star = 166,//ս����		
	 Orbcomm = 167,//Orbcomm
	 SubmarineBuoy = 17//��Ǳ�����ź�
 };

