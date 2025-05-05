#
# @lc app=leetcode.cn id=191 lang=python3
#
# [191] 位1的个数
#


# @lc code=start
class Solution:
    def hammingWeight(self, n: int) -> int:
        return n.bit_count()


# @lc code=end
