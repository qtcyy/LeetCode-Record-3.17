from functools import cache
from typing import List


class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        """
        记忆化搜索
        """
        inf = 2**31
        n = len(arr)

        @cache
        def dfs(i, j) -> int:
            if i == j:
                return 0
            res = inf
            for k in range(i, j):
                left = max(arr[i : k + 1])
                right = max(arr[k + 1 : j + 1])
                res = min(res, dfs(i, k) + dfs(k + 1, j) + left * right)
            return res

        return dfs(0, n - 1)


class Solution2:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        inf = 2**31

        f = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                res = inf
                for k in range(i, j):
                    left = max(arr[i : k + 1])
                    right = max(arr[k + 1 : j + 1])
                    res = min(res, f[i][k] + f[k + 1][j] + left * right)
                f[i][j] = res
        return f[0][n - 1]


def main():
    arr = [6, 2, 4]
    sol = Solution2()
    print(sol.mctFromLeafValues(arr))


main()
