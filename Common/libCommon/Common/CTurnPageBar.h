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
	void jumpPage(int);		//跳转

public slots:
	
	/**
	* @brief:  更新表格分页的状态
	* @param:  const int &allcount		总记录条数
	* @param:  const int &allpage		总页数
	* @param:  const int &curpage		当前页数
	* @return: void
	*/
	void onUpdataStaus(const int &allcount, const int &allpage, const int &curpage);

	/**
	* @brief:  跳转槽函数
	* @return: void
	*/
	void onjumpPage();
private:
	Ui::CTurnPageBar *ui;
	int				m_iPageCount;		//总页数
	int				m_iCurPage;			//保存当前页
};

#endif // CTURNPAGEBAR_H
