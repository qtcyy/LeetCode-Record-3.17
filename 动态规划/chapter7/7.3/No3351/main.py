from typing import List


class Solution:
    def sumOfGoodSubsequences(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        mx = max(nums) + 2
        f = [0] * mx
        cnt = [0] * mx
        for x in nums:
            c = cnt[x + 1] + cnt[x - 1] + 1
            f[x] = (f[x] + f[x - 1] + f[x + 1] + c * x) % MOD
            cnt[x] = (c + cnt[x]) % MOD
        return sum(f) % MOD


def main():
    nums = [3, 4, 5]
    sol = Solution()
    print(sol.sumOfGoodSubsequences(nums))


main()
