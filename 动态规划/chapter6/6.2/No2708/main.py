from typing import List


class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        n = len(nums)
        inf = 1 << 63
        f = [[-inf, inf] * 2 for _ in range(n + 1)]
        f[1] = [nums[0], nums[0]]
        for i in range(n):
            if nums[i] >= 0:
                f[i + 1][0] = max(nums[i], f[i][0], f[i][0] * nums[i])
                f[i + 1][1] = min(nums[i], f[i][1], f[i][1] * nums[i])
            else:
                f[i + 1][0] = max(nums[i], f[i][0], f[i][1] * nums[i])
                f[i + 1][1] = min(nums[i], f[i][1], f[i][0] * nums[i])
        return f[-1][0]


def main():
    nums = [3, -1, -5, 2, 5, -9]
    sol = Solution()
    print(sol.maxStrength(nums))


main()
