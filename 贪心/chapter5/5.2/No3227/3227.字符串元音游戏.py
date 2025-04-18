#
# @lc app=leetcode.cn id=3227 lang=python3
#
# [3227] 字符串元音游戏
#


# @lc code=start
class Solution:
    def doesAliceWin(self, s: str) -> bool:
        tot = s.count("a") + s.count("e") + s.count("i") + s.count("o") + s.count("u")
        return False if tot == 0 else True


# @lc code=end
