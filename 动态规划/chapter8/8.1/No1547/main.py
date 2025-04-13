from functools import cache
from typing import List


class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        cuts = [0] + cuts + [n]
        m = len(cuts)
        inf = 2**31

        @cache
        def dfs(i, j) -> int:
            if i + 1 == j:
                return 0
            res = inf
            for k in range(i + 1, j):
                res = min(res, dfs(i, k) + dfs(k, j) + cuts[j] - cuts[i])
            return res

        return dfs(0, m - 1)


class Solution2:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        cuts = [0] + cuts + [n]
        m = len(cuts)
        inf = 2**31

        f = [[0] * m for _ in range(m)]
        for i in range(m - 3, -1, -1):
            for j in range(i + 2, m):
                res = inf
                for k in range(i + 1, j):
                    res = min(res, f[i][k] + f[k][j] + cuts[j] - cuts[i])
                f[i][j] = res
        return f[0][m - 1]


def main():
    n = 9
    cuts = [5, 6, 1, 4, 2]
    sol = Solution2()
    print(sol.minCost(n, cuts))


main()
