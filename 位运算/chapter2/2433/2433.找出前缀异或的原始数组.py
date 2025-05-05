#
# @lc app=leetcode.cn id=2433 lang=python3
#
# [2433] 找出前缀异或的原始数组
#

# @lc code=start
from typing import List


class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        ans = [pref[0]]
        n = len(pref)
        last = pref[0]
        for i in range(1, n):
            ans.append(last ^ pref[i])
            last ^= ans[-1]
        return ans


# @lc code=end
