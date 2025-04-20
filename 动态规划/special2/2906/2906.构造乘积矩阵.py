#
# @lc app=leetcode.cn id=2906 lang=python3
#
# [2906] 构造乘积矩阵
#
from typing import List


# @lc code=start
class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        all = n * m
        MOD = 12345
        pre, suf = [1] * (all + 1), [1] * (all + 1)
        pos = 0
        for i in range(n):
            for j in range(m):
                pre[pos + 1] = (pre[pos] * grid[i][j]) % MOD
                pos += 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                pos -= 1
                suf[pos] = (suf[pos + 1] * grid[i][j]) % MOD
        ans = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                ans[i][j] = (pre[pos] * suf[pos + 1]) % MOD
                pos += 1
        return ans


# @lc code=end
