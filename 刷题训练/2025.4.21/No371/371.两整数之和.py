#
# @lc app=leetcode.cn id=371 lang=python3
#
# [371] 两整数之和
#


# @lc code=start
class Solution:
    def getSum2(self, a: int, b: int) -> int:
        def get_sum(a, b) -> int:
            if a == 0 or b == 0:
                return a ^ b
            return get_sum(a ^ b, (a & b) << 1)

        return get_sum(a, b)

    def getSum(self, a: int, b: int) -> int:
        a += b
        return a


# @lc code=end
