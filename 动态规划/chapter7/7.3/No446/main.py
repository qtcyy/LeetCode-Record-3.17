from collections import defaultdict
from typing import Dict, List


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        f = [defaultdict(int) for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for j in range(i):
                d = nums[i] - nums[j]
                f[i][d] += f[j][d] + 1
                if f[j][d]:
                    ans += f[j][d]
        return ans


def main():
    nums = [2, 4, 6, 8, 10]
    sol = Solution()
    print(sol.numberOfArithmeticSlices(nums))


main()
