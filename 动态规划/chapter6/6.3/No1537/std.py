from functools import cache
from typing import List


MOD = 10**9 + 7


class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        """
        每次有两种选择，继续走，或者跳到另一个数组
        """
        nums = [nums1, nums2]
        # 双指针预处理
        mp = [{}, {}]
        m, n = len(nums1), len(nums2)
        i = j = 0
        while i < m and j < n:
            if nums[0][i] == nums[1][j]:
                mp[0][i] = j
                mp[1][j] = i
                i += 1
                j += 1
            elif nums[0][i] < nums[1][j]:
                i += 1
            else:
                j += 1

        @cache
        def dfs(i: int, pos: int) -> int:
            if i == len(nums[pos]):
                return 0
            res = nums[pos][i] + dfs(i + 1, pos)
            if i in mp[pos]:
                res = max(res, nums[pos][i] + dfs(mp[pos][i] + 1, pos ^ 1))
            return res

        return max(dfs(0, 0), dfs(0, 1)) % MOD
