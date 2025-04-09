from typing import List

mn = lambda x, y: x if x < y else y
mx = lambda x, y: x if x > y else y


class Solution:
    def minUnlockedIndices(self, nums: List[int], locked: List[int]) -> int:
        n = len(nums)
        left_2, right_1 = n, -1
        left_3, right_2 = n, -1
        for i in range(n):
            if nums[i] == 1:
                right_1 = mx(right_1, i)
            elif nums[i] == 2:
                left_2 = mn(left_2, i)
                right_2 = mx(right_2, i)
            elif nums[i] == 3:
                left_3 = mn(left_3, i)
        if right_1 > left_3:
            return -1
        ans = 0
        if left_2 < right_1:
            ans += sum(locked[left_2:right_1])
        if left_3 < right_2:
            ans += sum(locked[left_3:right_2])
        return ans


def main():
    nums = [1, 2, 1, 1, 3, 2, 2]
    locked = [1, 0, 1, 1, 0, 1, 0]
    sol = Solution()
    print(sol.minUnlockedIndices(nums, locked))


main()
