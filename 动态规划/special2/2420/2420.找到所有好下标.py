#
# @lc app=leetcode.cn id=2420 lang=python3
#
# [2420] 找到所有好下标
#
from typing import List


# @lc code=start
class Solution:
    def goodIndices(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        pre = [1] * n
        suf = [1] * n
        for i in range(1, n):
            if nums[i] <= nums[i - 1]:
                pre[i] = pre[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                suf[i] = suf[i + 1] + 1
        ans = []
        for i in range(k, n - k):
            if pre[i - 1] >= k and suf[i + 1] >= k:
                ans.append(i)
        return ans


# @lc code=end
