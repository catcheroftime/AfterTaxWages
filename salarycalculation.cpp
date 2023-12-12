#include "salarycalculation.h"

#define MONTHS 12


static std::pair<double,int> getQuickRatio(double number)
{
    if (number > 960000)
        return {0.45, 181920};
    else if (number >660000)
        return {0.35, 85920};
    else if (number >420000)
        return {0.30, 52920};
    else if (number >300000)
        return {0.25, 31920};
    else if (number > 144000)
        return {0.20, 16920};
    else if (number >36000)
        return {0.10, 2520};
    else
        return {0.03, 0};
}

SalaryCalculation::SalaryCalculation()
{
    m_vecPersonalTax.resize(MONTHS);
    m_vecAfterTaxWages.resize(MONTHS);
    m_vecTaxStatistics.resize(MONTHS+1);
}

void SalaryCalculation::calculation()
{
    // 计算每月个人缴纳的社保金额
    m_ownSocialEec.EndowmentInsurance = m_baseSocialEecurity * m_ownRatio.EndowmentInsurance ;
    m_ownSocialEec.Medical = m_baseSocialEecurity * m_ownRatio.Medical ;
    m_ownSocialEec.Unemployment = m_baseSocialEecurity * m_ownRatio.Unemployment ;
    m_ownSocialEec.Maternity= m_baseSocialEecurity * m_ownRatio.Maternity ;
    m_ownSocialEec.Injury= m_baseSocialEecurity * m_ownRatio.Injury ;
    m_ownSocialEec.calTotal();

    // 计算每月公司缴纳的社保金额
    m_companySocialEec.EndowmentInsurance = m_baseSocialEecurity * m_companyRatio.EndowmentInsurance ;
    m_companySocialEec.Medical = m_baseSocialEecurity * m_companyRatio.Medical ;
    m_companySocialEec.Unemployment = m_baseSocialEecurity * m_companyRatio.Unemployment ;
    m_companySocialEec.Maternity= m_baseSocialEecurity * m_companyRatio.Maternity ;
    m_companySocialEec.Injury= m_baseSocialEecurity * m_companyRatio.Injury ;
    m_companySocialEec.calTotal();

    // 个人公积金部分
    double af_tax = m_baseAccumulationFund * m_accumulationFundRatio;
    double TaxableIncome = m_monthlySalary - m_ownSocialEec.total - af_tax ;

    m_vecTaxStatistics[0] = 0;

    for(int i = 0; i< MONTHS; i++)
    {
        double quickTax = TaxableIncome *(i+1) - 5000 * i;
        std::pair<double,int> quickcal = getQuickRatio(quickTax);
        double tax = quickTax * quickcal.first - quickcal.second - m_vecTaxStatistics[i];
        m_vecPersonalTax[i] = tax;
        m_vecTaxStatistics[i+1] = tax + m_vecTaxStatistics[i];
        m_vecAfterTaxWages[i] = m_monthlySalary - m_ownSocialEec.total - af_tax - tax;
    }
}
