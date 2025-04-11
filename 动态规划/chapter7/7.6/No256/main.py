from typing import List


class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        INF = 2**30
        f = [[INF] * 3 for _ in range(n + 1)]
        f[0] = [0] * 3
        for i, x in enumerate(costs):
            for j in range(3):
                for u in range(3):
                    if j == u:
                        continue
                    f[i + 1][j] = min(f[i + 1][j], f[i][u] + x[j])
        return min(f[-1])


def main():
    costs = [[17, 2, 17], [16, 16, 5], [14, 3, 19]]
    sol = Solution()
    print(sol.minCost(costs))


main()
