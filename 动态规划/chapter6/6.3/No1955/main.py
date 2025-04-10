from typing import List


class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        a, b, c = 0, 0, 0
        for x in nums:
            if x == 0:
                a = (a * 2 + 1) % MOD
            elif x == 1 and a:
                b = (b * 2 + a) % MOD
            elif x == 2 and b:
                c = (c * 2 + b) % MOD
        return c


def main():
    nums = [0, 1, 2, 0, 1, 2]
    sol = Solution()
    print(sol.countSpecialSubsequences(nums))


main()
