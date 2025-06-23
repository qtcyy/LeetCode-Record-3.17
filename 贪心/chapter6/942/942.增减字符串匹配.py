#
# @lc app=leetcode.cn id=942 lang=python3
#
# [942] 增减字符串匹配
#

# @lc code=start
from typing import List


class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        left, right = 0, len(s)
        res = []
        for x in s:
            if x == "I":
                res.append(left)
                left += 1
            else:
                res.append(right)
                right -= 1
        res.append(left)
        return res


# @lc code=end
