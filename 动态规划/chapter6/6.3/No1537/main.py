from functools import cache
from typing import List


mod = 10**9 + 7


class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        nums = [nums1, nums2]
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

        return max(dfs(0, 0), dfs(0, 1)) % mod


def main():
    nums1 = [2, 4, 5, 8, 10]
    nums2 = [4, 6, 8, 9]
    sol = Solution()
    print(sol.maxSum(nums1, nums2))


main()
