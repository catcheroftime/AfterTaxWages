#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "salarycalculation.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(u8"税后工资计算");

    init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->lineEdit_baseaf->setUnit(u8"元");
    ui->lineEdit_basesc->setUnit(u8"元");
    ui->lineEdit_monthsalary->setUnit(u8"元");
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


    ui->plainTextEdit->appendPlainText(QString(u8"每月工资：%1, 社保基数：%2, 公积金基数：%3, 公积金缴纳比例：%4% 时：\n").arg(monthlySalay).arg(socialEec).arg(accfund).arg(accfund_ratio*100));

    for(size_t i = 0; i< wages.size(); i++)
    {
        ui->plainTextEdit->appendPlainText(QString(u8"%1 月税后工资为：%2").arg(i+1).arg(wages.at(i)));
    }
    ui->plainTextEdit->appendPlainText(QString(""));

    ui->plainTextEdit->appendPlainText(QString(u8"全年税后收入为：%1").arg(total));
    ui->plainTextEdit->appendPlainText(QString(u8"可用公积金：%1").arg(cal.getTotalAccumulation()));
    ui->plainTextEdit->appendPlainText(QString(u8"实际可支配收入：%1\n").arg(total+cal.getTotalAccumulation()));

    ui->plainTextEdit->appendPlainText(QString(u8"个人纳税为：%1").arg(cal.getTotalTax()));
    ui->plainTextEdit->appendPlainText(QString(u8"个人缴纳公积金：%1").arg(cal.getTotalOwnAccumulation()));
    ui->plainTextEdit->appendPlainText(QString(u8"个人缴纳社保：%1").arg(cal.getTotalOwnSocialEecurity()));
    ui->plainTextEdit->appendPlainText(QString(u8"个人额外缴纳的部分(社保+公积金)：%1\n").arg(cal.getTotalOwnAccumulation() + cal.getTotalOwnSocialEecurity()));

    ui->plainTextEdit->appendPlainText(QString(u8"公司缴纳公积金：%1").arg(cal.getTotalOwnAccumulation()));
    ui->plainTextEdit->appendPlainText(QString(u8"公司缴纳社保：%1").arg(cal.getTotalCompanySocialEecurity()));
    ui->plainTextEdit->appendPlainText(QString(u8"公司额外缴纳的部分(社保+公积金)：%1").arg(cal.getTotalCompanySocialEecurity() + cal.getTotalOwnAccumulation()));
    ui->plainTextEdit->appendPlainText("===========================================\n");

}


void MainWindow::on_ptn_cal_clicked()
{
    calculation();
}

