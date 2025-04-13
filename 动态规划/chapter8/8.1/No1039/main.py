from functools import cache
from typing import List


class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        """
        记忆化搜索
        """
        n = len(values)
        inf = 1 << 30

        @cache
        def dfs(i, j) -> int:
            if i + 1 == j:
                return 0
            res = inf
            for k in range(i + 1, j):
                res = min(
                    res, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]
                )
            return int(res)

        return dfs(0, n - 1)


class Solution2:
    def minScoreTriangulation(self, values: List[int]) -> int:
        """
        递推
        """
        n = len(values)
        inf = 1 << 30
        f = [[0] * n for _ in range(n)]
        for i in range(n - 3, -1, -1):
            for j in range(i + 2, n):
                res = inf
                for k in range(i + 1, j):
                    res = min(
                        res, f[i][k] + f[k][j] + values[i] * values[k] * values[j]
                    )
                f[i][j] = res
        return f[0][n - 1]


def main():
    values = [1, 3, 1, 4, 1, 5]
    sol = Solution2()
    print(sol.minScoreTriangulation(values))


main()
