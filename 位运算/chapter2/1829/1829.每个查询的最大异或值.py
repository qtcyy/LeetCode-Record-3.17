#
# @lc app=leetcode.cn id=1829 lang=python3
#
# [1829] 每个查询的最大异或值
#

# @lc code=start
from typing import List


class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] ^ nums[i]
        base = 2**maximumBit - 1
        ans = []
        for i in range(n, 0, -1):
            ans.append((pre[i] | base) ^ pre[i])
        return ans


# @lc code=end
