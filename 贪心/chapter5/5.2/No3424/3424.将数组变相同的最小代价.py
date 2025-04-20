#
# @lc app=leetcode.cn id=3424 lang=python3
#
# [3424] 将数组变相同的最小代价
#
from typing import List


# @lc code=start
class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        # 不排序
        ans1 = 0
        for i, x in enumerate(arr):
            ans1 += abs(x - brr[i])

        # 排序
        ans2 = k
        arr.sort()
        brr.sort()
        for i, x in enumerate(arr):
            ans2 += abs(x - brr[i])
        return min(ans1, ans2)


# @lc code=end
