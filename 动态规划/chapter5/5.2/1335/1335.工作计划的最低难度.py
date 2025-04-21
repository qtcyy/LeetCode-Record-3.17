#
# @lc app=leetcode.cn id=1335 lang=python3
#
# [1335] 工作计划的最低难度
#

# @lc code=start
from typing import List


class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        """
        f[i][j] 前i天中划分j天的最小难度
        f[i+1][1]=max(a[:i])
        f[i+1][2]=f[j][1]+max(a[j:i])
        """
        n = len(jobDifficulty)
        if d > n:
            return -1
        if d == 1:
            return max(jobDifficulty)
        inf = 2**31
        f = [[inf] * (d + 1) for _ in range(n + 1)]
        for i in range(n):
            f[i + 1][1] = max(jobDifficulty[: i + 1])
        for k in range(2, d + 1):
            for i in range(n):
                for j in range(i, -1, -1):
                    f[i + 1][k] = min(
                        f[i + 1][k], f[j][k - 1] + max(jobDifficulty[j : i + 1])
                    )
        return f[-1][-1]


# @lc code=end
