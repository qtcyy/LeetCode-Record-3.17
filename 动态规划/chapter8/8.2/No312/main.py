from functools import cache
from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)

        @cache
        def dfs(i, j) -> int:
            if i + 1 == j:
                return 0
            best = 0
            for k in range(i + 1, j):
                res = nums[i] * nums[k] * nums[j]
                res += dfs(i, k) + dfs(k, j)
                best = max(best, res)
            return best

        return dfs(0, n - 1)


class Solution2:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                res = 0
                for k in range(i + 1, j):
                    tot = nums[i] * nums[k] * nums[j]
                    tot += f[i][k] + f[k][j]
                    res = max(res, tot)
                f[i][j] = res
        return f[0][-1]


def main():
    nums = [3, 1, 5, 8]
    sol = Solution2()
    print(sol.maxCoins(nums))


main()
