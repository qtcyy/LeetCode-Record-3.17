from functools import cache
from typing import List


class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n, m = len(nums), len(multipliers)

        @cache
        def dfs(i, left, right) -> int:
            if i == m:
                return 0
            return max(
                dfs(i + 1, left + 1, right) + nums[left] * multipliers[i],
                dfs(i + 1, left, right - 1) + nums[right] * multipliers[i],
            )

        return dfs(0, 0, n - 1)


class Solution2:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n, m = len(nums), len(multipliers)
        f = [[0] * (m + 1) for _ in range(m + 1)]
        for i in range(m - 1, -1, -1):
            for left in range(i + 1):
                f[i][left] = max(
                    f[i + 1][left + 1] + nums[left] * multipliers[i],
                    f[i + 1][left] + nums[n - 1 - i + left] * multipliers[i],
                )
        return f[0][0]


def main():
    nums = [-5, -3, -3, -2, 7, 1]
    multipliers = [-10, -5, 3, 4, 6]
    sol = Solution2()
    print(sol.maximumScore(nums, multipliers))


main()
