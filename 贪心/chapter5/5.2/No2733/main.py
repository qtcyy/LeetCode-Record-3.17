from typing import List


class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        mx, mn = max(nums), min(nums)
        for x in nums:
            if x != mx and x != mn:
                return x

        return -1


def main():
    nums = [3, 2, 1, 4]
    sol = Solution()
    print(sol.findNonMinOrMax(nums))


main()
