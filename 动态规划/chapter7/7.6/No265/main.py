from typing import List


class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        n, k = len(costs), len(costs[0])
        INF = 2**30
        f = [[INF] * k for _ in range(n + 1)]
        f[0] = [0] * k
        for i, x in enumerate(costs):
            for j in range(k):
                for u in range(k):
                    if j == u:
                        continue
                    f[i + 1][j] = min(f[i + 1][j], f[i][u] + x[j])
        return min(f[-1])


def main():
    costs = [[1, 5, 3], [2, 9, 4]]
    sol = Solution()
    print(sol.minCostII(costs))


main()
