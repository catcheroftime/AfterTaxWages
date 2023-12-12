#ifndef OWNLINEEDIT_H
#define OWNLINEEDIT_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QHBoxLayout;

class OwnLineEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)

public:
    explicit OwnLineEdit(QWidget *parent = nullptr);
    ~OwnLineEdit();

    QString text();
    void setText(QString text);

    QString unit();
    void setUnit(QString text);

private:
    void initView();

private:
    QLineEdit *m_numEdit;
    QLabel* m_labelUnit;
    QHBoxLayout * m_mainLayout;

};

#endif // OWNLINEEDIT_H
