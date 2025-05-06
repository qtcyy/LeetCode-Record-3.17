#
# @lc app=leetcode.cn id=1318 lang=python3
#
# [1318] 或运算的最小翻转次数
#


# @lc code=start
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ans = 0
        while a or b or c:
            if c & 1:
                if not a & 1 and not b & 1:
                    ans += 1
            else:
                if a & 1 and b & 1:
                    ans += 2
                elif a & 1 or b & 1:
                    ans += 1
            a >>= 1
            b >>= 1
            c >>= 1
        return ans


# @lc code=end
