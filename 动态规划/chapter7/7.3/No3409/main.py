from typing import List


class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        mx = max(nums)
        max_d = mx - min(nums)
        f = [[0] * (max_d + 2) for _ in range(n + 1)]
        last = [-1] * (mx + 1)
        for i, x in enumerate(nums):
            for j in range(max_d, -1, -1):
                f[i][j] = max(1, f[i][j + 1])
                if x - j >= 0 and last[x - j] != -1:
                    f[i][j] = max(f[i][j], f[last[x - j]][j] + 1)
                if x + j <= mx and last[x + j] != -1:
                    f[i][j] = max(f[i][j], f[last[x + j]][j] + 1)
            last[x] = i
        return max(map(max, f))


def main():
    nums = [6, 5, 3, 4, 2, 1]
    sol = Solution()
    print(sol.longestSubsequence(nums))


main()
