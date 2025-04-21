#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#


# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        flag = False
        if x < 0:
            flag = True
            x = -x
        s = str(x)
        s = s[::-1]
        val = int(s)
        if val >= 2**31:
            return 0
        if flag:
            return -val
        return val


# @lc code=end
