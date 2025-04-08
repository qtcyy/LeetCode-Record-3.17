from typing import List


class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        n = len(nums)

        if k == 0:
            return nums[0]

        if n == 1 and k % 2 == 1:
            return -1

        if k < n:
            if k > 1:
                return max(max(nums[: k - 1]), nums[k])
            else:  # k == 1
                return nums[1] if n > 1 else -1

        elif k == n:
            return max(nums[: n - 1]) if n > 1 else -1

        else:
            return max(nums) if n > 0 else -1


def main():
    sol = Solution()
    nums = [3, 2, 1]
    k = 1
    print(sol.maximumTop(nums, k))


main()
