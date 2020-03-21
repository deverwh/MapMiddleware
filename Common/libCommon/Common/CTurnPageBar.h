#ifndef CTURNPAGEBAR_H
#define CTURNPAGEBAR_H

#include <QWidget>
namespace Ui { class CTurnPageBar; };

class CTurnPageBar : public QWidget
{
	Q_OBJECT

public:
	CTurnPageBar(QWidget *parent = 0);
	~CTurnPageBar();

signals:
	void jumpPage(int);		//��ת

public slots:
	
	/**
	* @brief:  ���±���ҳ��״̬
	* @param:  const int &allcount		�ܼ�¼����
	* @param:  const int &allpage		��ҳ��
	* @param:  const int &curpage		��ǰҳ��
	* @return: void
	*/
	void onUpdataStaus(const int &allcount, const int &allpage, const int &curpage);

	/**
	* @brief:  ��ת�ۺ���
	* @return: void
	*/
	void onjumpPage();
private:
	Ui::CTurnPageBar *ui;
	int				m_iPageCount;		//��ҳ��
	int				m_iCurPage;			//���浱ǰҳ
};

#endif // CTURNPAGEBAR_H
