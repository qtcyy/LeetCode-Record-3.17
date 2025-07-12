#
# @lc app=leetcode.cn id=228 lang=python3
#
# [228] 汇总区间
#

# @lc code=start
from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        ans = []
        n = len(nums)
        if n == 0:
            return []
        res.append((nums[0], nums[0]))
        for i in range(n - 1):
            if nums[i] + 1 != nums[i + 1]:
                res.append((nums[i + 1], nums[i + 1]))
            else:
                res[-1] = (res[-1][0], nums[i + 1])
        for l, r in res:
            if l == r:
                ans.append(str(l))
            else:
                ans.append(str(l) + "->" + str(r))
        return ans


# @lc code=end
