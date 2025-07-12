#
# @lc app=leetcode.cn id=201 lang=python3
#
# [201] 数字范围按位与
#


# @lc code=start
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        m = (left ^ right).bit_length()
        return left & ~((1 << m) - 1)


# @lc code=end
