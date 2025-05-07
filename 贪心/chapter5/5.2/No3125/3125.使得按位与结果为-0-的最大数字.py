#
# @lc app=leetcode.cn id=3125 lang=python3
#
# [3125] 使得按位与结果为 0 的最大数字
#


# @lc code=start
class Solution:
    def maxNumber(self, n: int) -> int:
        ans = 0
        print(n.bit_length())
        for i in range(n.bit_length()):
            if n >> i & 1 == 0:
                ans |= 1 << i
        return ans


# @lc code=end
