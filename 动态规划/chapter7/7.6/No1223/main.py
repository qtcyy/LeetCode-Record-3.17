from typing import List


class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 10**9 + 7
        f = [[[0] * mx for mx in rollMax] for _ in range(n)]
        f[0] = [[1] * mx for mx in rollMax]
        for i in range(1, n):
            for last, mx in enumerate(rollMax):
                for left in range(mx):
                    res = 0
                    for j in range(6):
                        if j != last:
                            res += f[i - 1][j][-1]
                        elif left:
                            res += f[i - 1][j][left - 1]
                    f[i][last][left] = res % MOD
        return sum(f[-1][j][-1] for j in range(6)) % MOD


def main():
    n = 3
    rollMax = [1, 1, 1, 2, 2, 3]
    sol = Solution()
    print(sol.dieSimulator(n, rollMax))


main()
