#
# @lc app=leetcode.cn id=2680 lang=python3
#
# [2680] 最大或值
#
from typing import List


# @lc code=start
class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mul = 2**k
        pre, suf = [0] * (n + 1), [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] | nums[i]
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] | nums[i]
        ans = 0
        for i in range(n):
            ans = max(ans, nums[i] * mul | pre[i] | suf[i + 1])
        return ans


# @lc code=end
