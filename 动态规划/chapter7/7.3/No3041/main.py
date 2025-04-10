from collections import defaultdict
from typing import List


class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        nums.sort()
        f = defaultdict(int)
        for x in nums:
            f[x + 1] = f[x] + 1
            f[x] = f[x - 1] + 1
        return max(f.values())


def main():
    nums = [2, 1, 5, 1, 1]
    sol = Solution()
    print(sol.maxSelectedElements(nums))


main()
