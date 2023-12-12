#ifndef SALARYCALCULATION_H
#define SALARYCALCULATION_H

#include <vector>

class SalaryCalculation
{
public:
    // �����籣���ɱ���
    struct OwnSocialEecurityRatio
    {
        double EndowmentInsurance = 0.08;   // ���ϱ���
        double Medical = 0.02;              // ҽ�Ʊ���
        double Unemployment = 0.005;        // ʧҵ����
        double Maternity = 0;               // ��������
        double Injury = 0;                  // ���˱���
    };


    // ��˾�籣���ɱ���
    struct CompanySocialEecurityRatio
    {
        double EndowmentInsurance = 0.16;   // ���ϱ���
        double Medical = 0.064;             // ҽ�Ʊ���
        double Unemployment = 0.005;        // ʧҵ����
        double Maternity = 0;               // ��������
        double Injury = 0.002;              // ���˱���
    };


    struct SocialEecurity
    {
        double EndowmentInsurance;       // ���ϱ���
        double Medical ;                 // ҽ�Ʊ���
        double Unemployment ;            // ʧҵ����
        double Maternity;                // ��������
        double Injury;                   // ���˱���
        double total;                    // ��֧��

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

    // ������н
    void setMonthlySalary(double number)
    {
        m_monthlySalary = number;
    };

    // �����籣����
    void setBaseSocialEecurity(double number)
    {
        m_baseSocialEecurity = number;
    };

    // ���ø����籣���ɰٷֱ�
    void setOwnSocialEecurityRatio(OwnSocialEecurityRatio ratio)
    {
        m_ownRatio = ratio;
    };

    // ���ù�˾�籣���ɰٷֱ�
    void setCompanySocialEecurityRatio(CompanySocialEecurityRatio ratio)
    {
        m_companyRatio = ratio;
    };

    // ���ù���������ͽ��ɰٷֱ�
    void setAccumulationFund(double number, double ratio)
    {
        m_baseAccumulationFund = number;
        m_accumulationFundRatio = ratio;
    };


private:
    // ��н
    double m_monthlySalary;

    // �籣����
    double m_baseSocialEecurity;

    // ���������
    double m_baseAccumulationFund;

    // ��������ɰٷֱ�
    double m_accumulationFundRatio;

    // �����籣���ɰٷֱ�
    OwnSocialEecurityRatio m_ownRatio;

    // ��˾�籣���ɰٷֱ�
    CompanySocialEecurityRatio m_companyRatio;

    SocialEecurity m_ownSocialEec;
    SocialEecurity m_companySocialEec;

    // ÿ�¸�˰
    std::vector<double> m_vecPersonalTax;
    std::vector<double> m_vecTaxStatistics;

    // ÿ��˰��
    std::vector<double> m_vecAfterTaxWages;

};

#endif // SALARYCALCULATION_H
