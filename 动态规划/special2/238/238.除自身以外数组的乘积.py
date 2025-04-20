#
# @lc app=leetcode.cn id=238 lang=python3
#
# [238] 除自身以外数组的乘积
#
from typing import List


# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre, suf = [1] * (n + 1), [1] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] * nums[i]
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] * nums[i]
        ans = [0] * n
        for i in range(n):
            ans[i] = pre[i] * suf[i + 1]
        return ans


# @lc code=end
