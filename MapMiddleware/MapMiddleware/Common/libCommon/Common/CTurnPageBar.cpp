#include "CTurnPageBar.h"
#include "ui_CTurnPageBar.h"
#include <QMessageBox>
CTurnPageBar::CTurnPageBar(QWidget *parent)
: QWidget(parent), m_iPageCount(0), m_iCurPage(0)
{
	ui = new Ui::CTurnPageBar();
	ui->setupUi(this);
	connect(ui->firstPage_btn, &QPushButton::clicked, this, [=](){emit jumpPage(1); });
	connect(ui->prevPage_btn, &QPushButton::clicked, this, [=](){emit jumpPage(m_iCurPage-1); });
	connect(ui->nextPage_btn, &QPushButton::clicked, this, [=]() { emit jumpPage(m_iCurPage + 1); });
	connect(ui->lastPage_btn, &QPushButton::clicked, this, [=]() { emit jumpPage(m_iPageCount); });
	connect(ui->jumpPage_btn, &QPushButton::clicked, this, &CTurnPageBar::onjumpPage);
	connect(ui->curPage_lineEdit, &QLineEdit::returnPressed, this, &CTurnPageBar::onjumpPage);
}

CTurnPageBar::~CTurnPageBar()
{
	delete ui;
}

void CTurnPageBar::onUpdataStaus(const int &allcount, const int &allpage, const int &curpage)
{
	m_iPageCount = allpage;
	m_iCurPage = curpage;
	if (curpage == 1)	//	首页
	{
		ui->prevPage_btn->setEnabled(false);		//上一页不可选
		ui->firstPage_btn->setEnabled(false);		//首页不可选
		ui->nextPage_btn->setEnabled(true);
		ui->lastPage_btn->setEnabled(true);
	}else if (curpage == allpage)	//尾页
	{
		ui->nextPage_btn->setEnabled(false);		//下一页不可选
		ui->lastPage_btn->setEnabled(false);		//尾页不可选
		ui->prevPage_btn->setEnabled(true);
		ui->firstPage_btn->setEnabled(true);
	}
	else
	{
		ui->firstPage_btn->setEnabled(true);
		ui->prevPage_btn->setEnabled(true);
		ui->nextPage_btn->setEnabled(true);
		ui->lastPage_btn->setEnabled(true);
	}
	ui->curPage_lineEdit->setText(QString::number(curpage));		//界面显示当前页

	QString pageCount = QStringLiteral("/ %1 页").arg(allpage);
	ui->pageCount_label->setText(pageCount);				//界面显示总页数

	QString allCount = QStringLiteral("共 %1 条").arg(allcount);
	ui->recordCount_label->setText(allCount);				//界面显示总记录条数
}

void CTurnPageBar::onjumpPage()
{
	QString szText = ui->curPage_lineEdit->text();
	//数字正则表达式
	QRegExp	regExp("-?[0-9]*");
	//判断是否为数字
	if (!regExp.exactMatch(szText))
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("请输入数字！"));
		return;
	}
	int pageindex = szText.toInt();
	if (pageindex>m_iPageCount || pageindex<1)
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("页面超出范围，请重新输入！"));
		ui->curPage_lineEdit->setText(QString::number(m_iCurPage));		//界面显示当前页
		return;
	}
	emit jumpPage(pageindex);
}
