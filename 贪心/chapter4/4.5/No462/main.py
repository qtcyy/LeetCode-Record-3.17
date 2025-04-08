from typing import List


class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        base = nums[n // 2]
        ans = 0
        for x in nums:
            ans += abs(base - x)
        return ans


def main():
    nums = [1, 10, 2, 9]
    sol = Solution()
    print(sol.minMoves2(nums))


main()
