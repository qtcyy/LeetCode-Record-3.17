#
# @lc app=leetcode.cn id=1332 lang=python3
#
# [1332] 删除回文子序列
#


# @lc code=start
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if s == s[::-1]:
            return 1
        else:
            return 2


# @lc code=end
