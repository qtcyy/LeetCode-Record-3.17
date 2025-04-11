from collections import defaultdict
from typing import List


class Solution:
    def sumOfGoodSubsequences(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        f = defaultdict(int)
        cnt = defaultdict(int)
        for x in nums:
            c = cnt[x - 1] + cnt[x + 1] + 1
            f[x] = (f[x] + f[x - 1] + f[x + 1] + c * x) % MOD
            cnt[x] = (c + cnt[x]) % MOD
        return sum(f.values())


def main():
    nums = [1, 2, 1]
    sol = Solution()
    print(sol.sumOfGoodSubsequences(nums))


main()
