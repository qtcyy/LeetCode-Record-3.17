from functools import cache
from itertools import accumulate
from typing import List


class Solution:
    def mergeStones(self, stones: List[int], k: int) -> int:
        n = len(stones)
        if (n - 1) % (k - 1):
            return -1
        s = list(accumulate(stones, initial=0))

        @cache
        def dfs(i, j, p) -> int:
            if p == 1:
                return 0 if i == j else dfs(i, j, k) + s[j + 1] - s[i]
            return min(dfs(i, m, 1) + dfs(m + 1, j, p - 1) for m in range(i, j, k - 1))

        return dfs(0, n - 1, 1)


class Solution2:
    def mergeStones(self, stones: List[int], k: int) -> int:
        n = len(stones)
        if (n - 1) % (k - 1):
            return -1
        s = list(accumulate(stones, initial=0))

        f = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = min(f[i][m] + f[m + 1][j] for m in range(i, j, k - 1))
                if (j - i) % (k - 1) == 0:
                    f[i][j] += s[j + 1] - s[i]
        return f[0][n - 1]


def main():
    sol = Solution2()
    stones = [3, 2, 4, 1]
    K = 2
    print(sol.mergeStones(stones, K))


main()
