#
# @lc app=leetcode.cn id=2998 lang=python3
#
# [2998] 使 X 和 Y 相等的最少操作次数
#

# @lc code=start
from functools import cache


class Solution:
    @cache
    def minimumOperationsToMakeEqual(self, x: int, y: int) -> int:
        if x <= y:
            return y - x
        return min(
            x - y,
            self.minimumOperationsToMakeEqual(x // 11, y) + x % 11 + 1,
            self.minimumOperationsToMakeEqual(x // 11 + 1, y) + 11 - x % 11 + 1,
            self.minimumOperationsToMakeEqual(x // 5, y) + x % 5 + 1,
            self.minimumOperationsToMakeEqual(x // 5 + 1, y) + 5 - x % 5 + 1,
        )


# @lc code=end
