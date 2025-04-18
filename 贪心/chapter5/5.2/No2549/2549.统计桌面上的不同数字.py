#
# @lc app=leetcode.cn id=2549 lang=python3
#
# [2549] 统计桌面上的不同数字
#


# @lc code=start
class Solution:
    def distinctIntegers(self, n: int) -> int:
        if n == 1:
            return 1
        return n - 1


# @lc code=end
