# 税后工资计算器

![展示](image/show.png)

- **社保缴纳基数** 和 **公积金缴纳基数** 不填写，默认按照 **月工资** 计算
- 社保中个人和公司的具体系数，请调整 `SalaryCalculation` 类中的 `OwnSocialEecurityRatio` 和 `CompanySocialEecurityRatio` 结构体默认值
- 工资个税预扣预缴计算公式如下图

![预扣率表](image/quick.jpg)
