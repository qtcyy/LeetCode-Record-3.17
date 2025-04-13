from typing import List


class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        u = (1 << n) - 1
        f = [[0] * n for _ in range(u)]
        f[0] = [1] * n
        for s in range(1, u):
            for i, pre in enumerate(nums):
                if s >> i & 1:
                    continue
                for j, x in enumerate(nums):
                    if s >> j & 1 and (x % pre == 0 or pre % x == 0):
                        f[s][i] += f[s ^ (1 << j)][j]
        return sum(f[u ^ (1 << i)][i] for i in range(n)) % MOD


def main():
    nums = [1, 4, 3]
    sol = Solution()
    print(sol.specialPerm(nums))


main()
