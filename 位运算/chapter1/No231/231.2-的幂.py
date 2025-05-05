#
# @lc app=leetcode.cn id=231 lang=python3
#
# [231] 2 的幂
#


# @lc code=start
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n.bit_count() == 1


# @lc code=end
