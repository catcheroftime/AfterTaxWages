#include "ownlineedit.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegExpValidator>

OwnLineEdit::OwnLineEdit(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground);

    m_numEdit = new QLineEdit(this);
    m_numEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    m_numEdit->setFixedHeight(30);


    m_labelUnit = new QLabel(this);
    m_labelUnit->setText("%");
    m_labelUnit->setFixedHeight(30);

    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->setContentsMargins(10,0,10,0);
    m_mainLayout->addWidget(m_numEdit);
    m_mainLayout->addWidget(m_labelUnit);

    this->setStyleSheet("background:rgb(248, 248, 248); border-radius:6px;");
}

OwnLineEdit::~OwnLineEdit()
{
}

QString  OwnLineEdit::text()
{
    if(m_numEdit)
        return m_numEdit->text();
    return {""};
}

void  OwnLineEdit::setText(QString text)
{
    if (m_numEdit)
        m_numEdit->setText(text);
}

QString OwnLineEdit::unit()
{
    if(m_labelUnit)
        return m_labelUnit->text();

    return {""};
}

void OwnLineEdit::setUnit(QString text)
{
    if (m_labelUnit)
        m_labelUnit->setText(text);
}

void OwnLineEdit::initView()
{

}

