# 1.8 相邻不同

给定正整数数组，每次操作，把数组中的两个数各减少一，并去掉变成 0 的数。目标：使最后剩下的数最小，或者最大化操作次数。

由于每次操作的都是两个下标不同的数，把这些下标按顺序拼接，可以构造出一个相邻元素不同的序列。例如 (1,2),(2,3),(3,4) 这三个操作，可以拼接成 [1,2,3,2,3,4]。

**题目列表**

- [2335. 装满杯子需要的最短总时长](https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/description/)
- [1753. 移除石子的最大得分](https://leetcode.cn/problems/maximum-score-from-removing-stones/description/)
