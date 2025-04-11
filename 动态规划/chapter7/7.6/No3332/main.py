from typing import List

mx = lambda x, y: x if x > y else y


class Solution:
    def maxScore(
        self, n: int, k: int, stayScore: List[List[int]], travelScore: List[List[int]]
    ) -> int:
        f = [[0] * n for _ in range(k + 1)]
        for i in range(0, k):
            for u in range(n):
                f[i + 1][u] = f[i][u] + stayScore[i][u]
                for v in range(n):
                    if u == v:
                        continue
                    f[i + 1][u] = mx(f[i + 1][u], f[i][v] + travelScore[v][u])
        return max(f[k])


def main():
    n = 3
    k = 2
    stayScore = [[3, 4, 2], [2, 1, 2]]
    travelScore = [[0, 2, 1], [2, 0, 4], [3, 2, 0]]
    sol = Solution()
    print(sol.maxScore(n, k, stayScore, travelScore))


main()
