#
# @lc app=leetcode.cn id=2139 lang=python3
#
# [2139] 得到目标值的最少行动次数
#


# @lc code=start
class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        n = target
        ans = 0
        while n != 1:
            if n & 1:
                ans += 1
                n -= 1
                continue
            if maxDoubles:
                maxDoubles -= 1
                n //= 2
                ans += 1
            else:
                ans += n - 1
                break
        return ans


# @lc code=end
