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
	if (curpage == 1)	//	��ҳ
	{
		ui->prevPage_btn->setEnabled(false);		//��һҳ����ѡ
		ui->firstPage_btn->setEnabled(false);		//��ҳ����ѡ
		ui->nextPage_btn->setEnabled(true);
		ui->lastPage_btn->setEnabled(true);
	}else if (curpage == allpage)	//βҳ
	{
		ui->nextPage_btn->setEnabled(false);		//��һҳ����ѡ
		ui->lastPage_btn->setEnabled(false);		//βҳ����ѡ
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
	ui->curPage_lineEdit->setText(QString::number(curpage));		//������ʾ��ǰҳ

	QString pageCount = QStringLiteral("/ %1 ҳ").arg(allpage);
	ui->pageCount_label->setText(pageCount);				//������ʾ��ҳ��

	QString allCount = QStringLiteral("�� %1 ��").arg(allcount);
	ui->recordCount_label->setText(allCount);				//������ʾ�ܼ�¼����
}

void CTurnPageBar::onjumpPage()
{
	QString szText = ui->curPage_lineEdit->text();
	//����������ʽ
	QRegExp	regExp("-?[0-9]*");
	//�ж��Ƿ�Ϊ����
	if (!regExp.exactMatch(szText))
	{
		QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("���������֣�"));
		return;
	}
	int pageindex = szText.toInt();
	if (pageindex>m_iPageCount || pageindex<1)
	{
		QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("ҳ�泬����Χ�����������룡"));
		ui->curPage_lineEdit->setText(QString::number(m_iCurPage));		//������ʾ��ǰҳ
		return;
	}
	emit jumpPage(pageindex);
}
