# 8.1 最长回文子序列

两种方法

### 方法 1

$t = s[::-1]$
求 LCS

### 方法 2

区间 DP

$f[i][j]$表示区间$[i,j]$的最长回文序列
状态：选或不选

- $s[i]==s[j]$ 选
  $f[i][j]=f[i+1][j-1]+2$
- $s[i]\neq s[j]$ 不选 转移
  $f[i][j]=max(f[i+1][j],f[i][j-1])$

**题目列表**

- [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/description/)
