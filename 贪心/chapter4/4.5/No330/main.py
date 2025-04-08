from typing import List


class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        s, ans = 1, 0
        i = 0
        while s <= n:
            if i < len(nums) and nums[i] <= s:
                s += nums[i]
                i += 1
            else:
                s *= 2
                ans += 1
        return ans


def main():
    nums = [1, 5, 10]
    n = 20
    sol = Solution()
    print(sol.minPatches(nums, n))


main()
