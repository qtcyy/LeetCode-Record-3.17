from typing import List


class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        ans = 0
        for m in range(k):
            f = [0] * k
            for x in nums:
                x %= k
                f[x] = f[m - x] + 1
            ans = max(ans, max(f))
        return ans


def main():
    nums = [1, 4, 2, 3, 1, 4]
    k = 3
    sol = Solution()
    print(sol.maximumLength(nums, k))


main()
