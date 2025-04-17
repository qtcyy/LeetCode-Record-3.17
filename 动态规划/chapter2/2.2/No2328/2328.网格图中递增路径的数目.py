#
# @lc app=leetcode.cn id=2328 lang=python3
#
# [2328] 网格图中递增路径的数目
#

# @lc code=start
from functools import cache
from typing import List


class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])

        @cache
        def dfs(i: int, j: int) -> int:
            res = 1
            for x, y in (i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1):
                if 0 <= x < m and 0 <= y < n and grid[x][y] > grid[i][j]:
                    res += dfs(x, y)
            return res % MOD

        return sum(dfs(i, j) for i in range(m) for j in range(n)) % MOD


# @lc code=end
