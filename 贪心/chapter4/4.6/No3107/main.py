from typing import List


class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        base = nums[n // 2]
        ans = 0
        if k == base:
            return 0
        if k < base:
            for i in range(n // 2, -1, -1):
                if nums[i] > k:
                    ans += nums[i] - k
                else:
                    break
        else:
            for i in range(n // 2, n):
                if nums[i] < k:
                    ans += k - nums[i]
                else:
                    break
        return ans


def main():
    nums = [2, 5, 6, 8, 5]
    k = 7
    sol = Solution()
    print(sol.minOperationsToMakeMedianK(nums, k))


main()
