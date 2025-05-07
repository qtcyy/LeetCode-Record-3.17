#
# @lc app=leetcode.cn id=3282 lang=python3
#
# [3282] 到达数组末尾的最大得分
#

# @lc code=start
from typing import List


class Solution:
    def findMaximumScore(self, nums: List[int]) -> int:
        ans = mx = 0
        for x in nums[:-1]:
            mx = max(mx, x)
            ans += mx
        return ans


# @lc code=end
