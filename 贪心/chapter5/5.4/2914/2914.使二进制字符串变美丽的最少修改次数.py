#
# @lc app=leetcode.cn id=2914 lang=python3
#
# [2914] 使二进制字符串变美丽的最少修改次数
#


# @lc code=start
class Solution:
    def minChanges(self, s: str) -> int:
        n = len(s)
        ans = 0
        for i in range(0, n, 2):
            if s[i] != s[i + 1]:
                ans += 1
        return ans


# @lc code=end
