from typing import List


class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        arr = nums[::-1]
        ans = 0
        for i in range(n):
            ans = max(ans, nums[i] + arr[i])
        return ans


def main():
    nums = [3, 5, 4, 2, 4, 6]
    sol = Solution()
    print(sol.minPairSum(nums))


main()
