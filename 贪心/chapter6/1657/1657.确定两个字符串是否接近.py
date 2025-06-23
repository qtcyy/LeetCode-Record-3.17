#
# @lc app=leetcode.cn id=1657 lang=python3
#
# [1657] 确定两个字符串是否接近
#

# @lc code=start
from collections import Counter


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        return (
            len(word1) == len(word2)
            and set(word1) == set(word2)
            and Counter(Counter(word1).values()) == Counter(Counter(word2).values())
        )


# @lc code=end
