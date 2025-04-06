# 1.7 交换论证法

交换论证法（exchange argument）用于证明一类贪心算法的正确性，也可以用来启发思考。做法如下：

对于题目，猜想按照「某种顺序」处理数据，可以得到最优解。
交换顺序中的两个元素 \(a_i\) 和 \(a_j\)，计算交换后的答案。
对比交换前后的答案。如果交换后，答案没有变得更优，则说明猜想成立。
也可以不用猜想，而是计算「先 \(a_i\) 后 \(a_j\)」和「先 \(a_j\) 后 \(a_i\)」对应的答案，通过比较两个答案谁更优，来确定按照何种顺序处理数据。

**题目列表**

- [2895. 最小处理时间](https://leetcode.cn/problems/minimum-processing-time/description/)
- [1665. 完成所有任务的最少初始能量](https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/description/)
- [3273. 对 Bob 造成的最少伤害](https://leetcode.cn/problems/minimum-amount-of-damage-dealt-to-bob/description/)
