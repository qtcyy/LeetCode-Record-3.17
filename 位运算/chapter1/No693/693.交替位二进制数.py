#
# @lc app=leetcode.cn id=693 lang=python3
#
# [693] 交替位二进制数
#


# @lc code=start
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        cur = n & 1
        while n:
            if cur != n & 1:
                return False
            n >>= 1
            cur = 1 - cur
        return True


# @lc code=end
