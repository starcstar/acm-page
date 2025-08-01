# 2025 集训队选拔方案

为了选拔并组建新一赛季的 NUAAXCPC 集训队，我们将秉持公平、公正、公开的原则，通过一系列的训练与比赛对候选队员进行综合考评。具体的选拔方案与安排如下：

## 一、 综合成绩构成

选拔的最终依据为选手的综合成绩，其计算方式如下：

**综合成绩 = 个人集训成绩 (A) + 校赛成绩 (B) + 附加分 (C)**

## 二、 各部分成绩细则

### A. 个人集训成绩 (满分100分)

此部分成绩旨在考察选手的持续学习能力与坚韧毅力。

* **成绩来源**：共计7场个人训练赛（杭电春季联赛第4场至第10场），取其中成绩最好的**5场**计入最终成绩。
* **单场积分规则**：每场训练赛满分20分，计算公式为：
    $$R_i = 15 \times \frac{n - \text{place} + 1}{n} \times \frac{\text{solved}}{\text{maxsolved}} + 5 \times \frac{\text{upsolved}}{\text{problemCount}}$$
* **公式参数说明**：
    * $R_i$：单场比赛得分。
    * $n$：为 $\max(40, \text{本场选手数})$，以保证比赛规模较小时分数的公平性。
    * $\text{place}$：选手在该场比赛中的排名（从1开始）。
    * $\text{solved}$：选手在该场比赛中正确解答（AC）的题目数量。
    * $\text{maxsolved}$：该场比赛第一名选手的 AC 题数。
    * $\text{upsolved}$：选手在该场比赛的补题数量（**补题提交截止时间为2025年5月28日**）。
    * $\text{problemCount}$：该场比赛的总题目数。

### B. 校赛成绩

此部分成绩旨在考察选手在正式比赛环境下的竞技水平与抗压能力。

* **计算公式**：
    $$\text{校赛总成绩} = 0.03 \times \text{初赛成绩} + 0.07 \times \text{决赛成绩}$$

### C. 附加分

此部分用于鼓励积极的训练态度、诚信的比赛精神以及对算法竞赛的持续热情。

* **扣分项**：
    * **无故缺勤/态度不端**：无故不参加日常训练或未认真完成训练报告者，每次扣 **4** 分。
    * **违反诚信**：在日常训练和校赛中出现抄袭、代打等违反比赛诚信行为者，一经发现，立即扣除 **100** 分。

* **加分项** (基于 Codeforces 或 AtCoder 的个人能力评级)：
    * Codeforces **绿名** 或 AtCoder **绿名**：**+10** 分
    * Codeforces **青名** 或 AtCoder **1000分以上**：**+30** 分
    * Codeforces **蓝名** 或 AtCoder **青名**：**+60** 分
    * Codeforces **紫名** 或 AtCoder **蓝名**：**+100** 分
    * Codeforces **橙名及以上** 或 AtCoder **黄名及以上**：**+2147483647** 分 (直接获得入队资格)