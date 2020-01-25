#ifndef SystemIDDef_H
#define SystemIDDef_H

#include <QString>

//����߼�ID

//�����ϵͳ
#define		SYSTEM_RADAR					0x0001			//�����ϵͳ���
#define		SOFT_RS_SNUM_RADAR				0x000101		//�״��ź�����Կ�����̱��
#define		SOFT_RS_RADARSIGDETECT_1		0x00010101		//�״��ź�����Կ����1
#define		SOFT_RS_RADARSIGDETECT_2		0x00010102		//�״��ź�����Կ����2

//ͨ���ϵͳ
#define		SYSTEM_COM						0x0002			//ͨ���ϵͳ���
#define		SOFT_CSR_SNUM_HOPFREQ			0x000201		//��Ƶ�ź�����Կ�����̱��
#define		SOFT_CSR_SNUM_GEN				0x000202		//�����ź�����Կ�����̱��
#define		SOFT_CSR_SUBMARINE				0x00020300		//���������ź������Կ����
#define		SOFT_CSR_SNUM_UNLINE			0x000204		//ͨ�����߷�������̱��

//Link16��ϵͳ
#define		SYSTEM_LINK16					0x0003			//Link16��ϵͳ���
#define		SOFT_TLR_LINK16SIGDETECT		0x00030100		//Link16�ź�����Կ����

//IFF / TACAN��ϵͳ
#define		SYSTEM_IFFTACAN					0x0004			//IFF / TACAN��ϵͳ���
#define		SOFT_ITR_IFFTACANSIGDETECT		0x00040100		//IFF / TACAN�ź�����Կ����

//�����ϵͳ
#define		SYSTEM_LIGHT					0x0005			//�����ϵͳ���
#define		SOFT_OF_LIGHTSIGDETECT			0x00050100		//�������Կ����

//ָ�ط�ϵͳ
#define		SYSTEM_CMDCTRL						0x0006			//ָ�ط�ϵͳ���
#define		SOFT_CIS_DATADISPATCH				0x00060100		//����ַ�����������
#define		SOFT_CIS_SNUM_INTELLIGMANAGER		0x000602		//�鱨�ۺϴ�������̱��
#define		SOFT_CIS_SITUATIONMANAGER			0x00060300		//̬���鱨�������
#define		SOFT_CIS_TASKMANAGER				0x00060400		//����������
#define		SOFT_CIS_SNUM_SITUATIONDISPLAY		0x000605		//̬����ʾ����̱��
#define		SOFT_CIS_SNUM_USERROLEMANGER		0x000606		//�û���ɫװ������̱��
#define		SOFT_CIS_SNUM_INTERNAVDISPATCH		0x000607		//�ߵ����շַ�����̱��
#define		SOFT_CIS_LAUNCHWARNDISPATCH			0x00060800		//����澯�ַ����
#define		SOFT_CIS_AISDISPATCH				0x00060900		//AIS���շַ����
#define		SOFT_CIS_VOICEIDENTIFY				0x00060A00		//����ʶ�����

//����ͨ�ŷ�ϵͳ
#define		SYSTEM_TASKCOM						0x0007			//����ͨ�ŷ�ϵͳ���
#define		SOFT_CS_TASKCOMMUNICATE				0x00070100		//����ͨ���Կ����
#define		SOFT_CS_SNUM_IMMEDICOMMUNICATE		0x000702		//��ʱͨ����̱��

//��ϵͳ����ַ���
#define		STR_SYSTEM_RADAR		QString("0x0001")
#define		STR_SYSTEM_COM			QString("0x0002")
#define		STR_SYSTEM_LINK16		QString("0x0003")
#define		STR_SYSTEM_IFFTACAN		QString("0x0004")
#define		STR_SYSTEM_LIGHT		QString("0x0005")
#define		STR_SYSTEM_CMDCTRL		QString("0x0006")
#define		STR_SYSTEM_TASKCOM		QString("0x0007")

#endif // !SystemIDDef_H
