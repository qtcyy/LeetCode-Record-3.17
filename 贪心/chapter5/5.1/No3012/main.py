from typing import List


class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        base = min(nums)
        for x in nums:
            if x % base:
                return 1
        cnt = nums.count(base)
        return (cnt + 1) // 2


def main():
    nums = [5, 5, 5, 10, 5]
    sol = Solution()
    print(sol.minimumArrayLength(nums))


main()
