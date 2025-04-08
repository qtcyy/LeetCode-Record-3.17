from math import inf
from typing import List


class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses.sort()
        n = len(houses)
        dist = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(i, n):
                mid = (i + j) // 2
                for t in range(i, j + 1):
                    dist[i][j] += abs(houses[t] - houses[mid])

        f = [[inf] * (k + 1) for _ in range(n)]
        f[0][1] = 0

        for i in range(n):
            if i > 0:
                f[i][1] = dist[0][i]

            for t in range(2, min(i + 2, k + 1)):
                for j in range(i):
                    f[i][t] = min(f[i][t], f[j][t - 1] + dist[j + 1][i])

        return int(f[n - 1][k]) if f[n - 1][k] != inf else 0


def main():
    sol = Solution()
    houses = [2, 3, 5, 12, 18]
    k = 2
    print(sol.minDistance(houses=houses, k=k))


main()
