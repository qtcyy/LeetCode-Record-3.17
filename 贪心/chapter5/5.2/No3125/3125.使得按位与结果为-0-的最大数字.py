#
# @lc app=leetcode.cn id=3125 lang=python3
#
# [3125] 使得按位与结果为 0 的最大数字
#


# @lc code=start
class Solution:
    def maxNumber(self, n: int) -> int:
        return (1 << (n.bit_length() - 1)) - 1


# @lc code=end
