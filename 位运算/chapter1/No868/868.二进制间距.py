#
# @lc app=leetcode.cn id=868 lang=python3
#
# [868] 二进制间距
#


# @lc code=start
class Solution:
    def binaryGap(self, n: int) -> int:
        last, i = 0, 0
        ans = 0
        while n:
            i += 1
            if n & 1:
                if not last:
                    last = i
                else:
                    ans = max(ans, i - last)
                    last = i
            n >>= 1
        return ans


# @lc code=end
