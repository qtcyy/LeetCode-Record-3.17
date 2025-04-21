#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#

# @lc code=start
from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        i, j = 0, n - 1
        res = 0
        while i < j:
            mn = min(height[i], height[j])
            res = max(res, (j - i) * mn)
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return res


# @lc code=end
