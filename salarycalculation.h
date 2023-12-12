#ifndef SALARYCALCULATION_H
#define SALARYCALCULATION_H

#include <vector>

class SalaryCalculation
{
public:
    // 个人社保缴纳比例
    struct OwnSocialEecurityRatio
    {
        double EndowmentInsurance = 0.08;   // 养老保险
        double Medical = 0.02;              // 医疗保险
        double Unemployment = 0.005;        // 失业保险
        double Maternity = 0;               // 生育保险
        double Injury = 0;                  // 工伤保险
    };


    // 公司社保缴纳比例
    struct CompanySocialEecurityRatio
    {
        double EndowmentInsurance = 0.16;   // 养老保险
        double Medical = 0.064;             // 医疗保险
        double Unemployment = 0.005;        // 失业保险
        double Maternity = 0;               // 生育保险
        double Injury = 0.002;              // 工伤保险
    };


    struct SocialEecurity
    {
        double EndowmentInsurance;       // 养老保险
        double Medical ;                 // 医疗保险
        double Unemployment ;            // 失业保险
        double Maternity;                // 生育保险
        double Injury;                   // 工伤保险
        double total;                    // 总支出

        void calTotal()
        {
            total = EndowmentInsurance + Medical + Unemployment + Maternity + Injury;
        }
    };


    SalaryCalculation();

    void calculation();

    std::vector<double> getAfterTaxWages()
    {
        return m_vecAfterTaxWages;
    }

    double getTotalTax()
    {
        return *(m_vecTaxStatistics.end()-1);
    }

    double getTotalAccumulation()
    {
        return m_baseAccumulationFund*m_accumulationFundRatio*12*2;
    }

    double getTotalOwnAccumulation()
    {
        return m_baseAccumulationFund*m_accumulationFundRatio*12;
    }

    double getTotalOwnSocialEecurity()
    {
        return m_ownSocialEec.total*12;
    }

    double getTotalCompanySocialEecurity()
    {
        return m_companySocialEec.total*12;
    }

    // 设置月薪
    void setMonthlySalary(double number)
    {
        m_monthlySalary = number;
    };

    // 设置社保基数
    void setBaseSocialEecurity(double number)
    {
        m_baseSocialEecurity = number;
    };

    // 设置个人社保缴纳百分比
    void setOwnSocialEecurityRatio(OwnSocialEecurityRatio ratio)
    {
        m_ownRatio = ratio;
    };

    // 设置公司社保缴纳百分比
    void setCompanySocialEecurityRatio(CompanySocialEecurityRatio ratio)
    {
        m_companyRatio = ratio;
    };

    // 设置公积金基数和缴纳百分比
    void setAccumulationFund(double number, double ratio)
    {
        m_baseAccumulationFund = number;
        m_accumulationFundRatio = ratio;
    };


private:
    // 月薪
    double m_monthlySalary;

    // 社保基数
    double m_baseSocialEecurity;

    // 公积金基数
    double m_baseAccumulationFund;

    // 公积金缴纳百分比
    double m_accumulationFundRatio;

    // 个人社保缴纳百分比
    OwnSocialEecurityRatio m_ownRatio;

    // 公司社保缴纳百分比
    CompanySocialEecurityRatio m_companyRatio;

    SocialEecurity m_ownSocialEec;
    SocialEecurity m_companySocialEec;

    // 每月个税
    std::vector<double> m_vecPersonalTax;
    std::vector<double> m_vecTaxStatistics;

    // 每月税后
    std::vector<double> m_vecAfterTaxWages;

};

#endif // SALARYCALCULATION_H
