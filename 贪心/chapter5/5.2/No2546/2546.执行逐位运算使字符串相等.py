#
# @lc app=leetcode.cn id=2546 lang=python3
#
# [2546] 执行逐位运算使字符串相等
#


# @lc code=start
class Solution:
    def makeStringsEqual(self, s: str, target: str) -> bool:
        if s.count("0") == 0 and target.count("1") == 0:
            return False
        if s.count("1") == 0 and target.count("1"):
            return False
        if s.count("1") and target.count("1") == 0:
            return False
        return True


# @lc code=end
