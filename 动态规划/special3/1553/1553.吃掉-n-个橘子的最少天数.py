#
# @lc app=leetcode.cn id=1553 lang=python3
#
# [1553] 吃掉 N 个橘子的最少天数
#

# @lc code=start
from functools import cache


class Solution:
    def minDays(self, n: int) -> int:
        @cache
        def dfs(x: int) -> int:
            if x <= 1:
                return x
            return min(dfs(x // 2) + x % 2, dfs(x // 3) + x % 3) + 1

        return dfs(n)


# @lc code=end
