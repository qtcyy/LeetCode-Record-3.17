# 9.1 排列型 ① 相邻无关

暴力做法是枚举所有排列，对每个排列计算和题目有关的值，时间复杂度（通常来说）是 $O(n!)$。可以解决 $n≤10$ 的问题。

状压 DP 可以把时间复杂度（通常来说）优化至 $O(n\cdot 2^n)$。可以解决 $n≤20$ 的问题。

一般有两种定义方式：

1. 定义 $f[S]$ 表示已经排列好的元素（下标）集合为 $S$ 时，和题目有关的最优值。通过枚举当前位置要填的元素（下标）来转移。
2. 定义 $f[S]$ 表示可以选的元素（下标）集合为 $S$ 时，和题目有关的最优值。通过枚举当前位置要填的元素（下标）来转移。

**题目列表**

- [526. 优美的排列](https://leetcode.cn/problems/beautiful-arrangement/description/)
- [3376. 破解锁的最少时间 I](https://leetcode.cn/problems/minimum-time-to-break-locks-i/description/)
- [1879. 两个数组最小的异或值之和](https://leetcode.cn/problems/minimum-xor-sum-of-two-arrays/description/)
- [2850. 将石头分散到网格图的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/description/)
