from typing import List


class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        a = sorted(zip(nums, cost))
        target = (sum(cost) + 1) // 2
        s = 0
        for n, c in a:
            s += c
            if s >= target:
                return sum(abs(n - x) * cc for x, cc in a)
        return 0


def main():
    sol = Solution()
    nums = [1, 3, 5, 2]
    cost = [2, 3, 1, 14]
    print(sol.minCost(nums=nums, cost=cost))


main()
