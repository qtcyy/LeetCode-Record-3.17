from typing import List


class Solution:
    def minCost(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(n + 1)]
        f[n] = nums
        for i in range(n - 1):
            f[n - 1][i] = max(nums[-1], nums[i])
        for i in range(n - 3 + n % 2, 0, -2):
            b, c = nums[i], nums[i + 1]
            for j in range(i):
                a = nums[j]
                f[i][j] = min(
                    f[i + 2][j] + max(b, c),
                    f[i + 2][i] + max(a, c),
                    f[i + 2][i + 1] + max(a, b),
                )
        return f[1][0]


def main():
    nums = [6, 2, 8, 4]
    sol = Solution()
    print(sol.minCost(nums))


main()
