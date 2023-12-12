#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "salarycalculation.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(u8"˰���ʼ���");

    init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->lineEdit_baseaf->setUnit(u8"Ԫ");
    ui->lineEdit_basesc->setUnit(u8"Ԫ");
    ui->lineEdit_monthsalary->setUnit(u8"Ԫ");
}

void MainWindow::calculation()
{
    SalaryCalculation cal;


    double monthlySalay = ui->lineEdit_monthsalary->text().toDouble();

    double socialEec = monthlySalay;
    if(!ui->lineEdit_basesc->text().isEmpty())
        socialEec = ui->lineEdit_basesc->text().toDouble();

    double accfund = monthlySalay;
    if(!ui->lineEdit_baseaf->text().isEmpty())
        ui->lineEdit_baseaf->text().toDouble();
    double accfund_ratio = ui->lineEdit_afratio->text().toDouble()/100;


    cal.setMonthlySalary(monthlySalay);
    cal.setBaseSocialEecurity(socialEec);
    cal.setAccumulationFund(accfund,accfund_ratio);

    cal.calculation();

    std::vector<double> wages = cal.getAfterTaxWages();

    double total = 0;
    for(auto number:wages)
        total += number;


    ui->plainTextEdit->appendPlainText(QString(u8"ÿ�¹��ʣ�%1, �籣������%2, �����������%3, ��������ɱ�����%4% ʱ��\n").arg(monthlySalay).arg(socialEec).arg(accfund).arg(accfund_ratio*100));

    for(size_t i = 0; i< wages.size(); i++)
    {
        ui->plainTextEdit->appendPlainText(QString(u8"%1 ��˰����Ϊ��%2").arg(i+1).arg(wages.at(i)));
    }
    ui->plainTextEdit->appendPlainText(QString(""));

    ui->plainTextEdit->appendPlainText(QString(u8"ȫ��˰������Ϊ��%1").arg(total));
    ui->plainTextEdit->appendPlainText(QString(u8"���ù�����%1").arg(cal.getTotalAccumulation()));
    ui->plainTextEdit->appendPlainText(QString(u8"ʵ�ʿ�֧�����룺%1\n").arg(total+cal.getTotalAccumulation()));

    ui->plainTextEdit->appendPlainText(QString(u8"������˰Ϊ��%1").arg(cal.getTotalTax()));
    ui->plainTextEdit->appendPlainText(QString(u8"���˽��ɹ�����%1").arg(cal.getTotalOwnAccumulation()));
    ui->plainTextEdit->appendPlainText(QString(u8"���˽����籣��%1").arg(cal.getTotalOwnSocialEecurity()));
    ui->plainTextEdit->appendPlainText(QString(u8"���˶�����ɵĲ���(�籣+������)��%1\n").arg(cal.getTotalOwnAccumulation() + cal.getTotalOwnSocialEecurity()));

    ui->plainTextEdit->appendPlainText(QString(u8"��˾���ɹ�����%1").arg(cal.getTotalOwnAccumulation()));
    ui->plainTextEdit->appendPlainText(QString(u8"��˾�����籣��%1").arg(cal.getTotalCompanySocialEecurity()));
    ui->plainTextEdit->appendPlainText(QString(u8"��˾������ɵĲ���(�籣+������)��%1").arg(cal.getTotalCompanySocialEecurity() + cal.getTotalOwnAccumulation()));
    ui->plainTextEdit->appendPlainText("===========================================\n");

}


void MainWindow::on_ptn_cal_clicked()
{
    calculation();
}

