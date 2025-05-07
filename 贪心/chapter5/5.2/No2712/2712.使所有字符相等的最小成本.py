#
# @lc app=leetcode.cn id=2712 lang=python3
#
# [2712] 使所有字符相等的最小成本
#


# @lc code=start
class Solution:
    def minimumCost(self, s: str) -> int:
        n = len(s)
        ans = 0
        for i in range(1, n):
            if s[i - 1] != s[i]:
                ans += min(i, n - i)
        return ans


# @lc code=end
