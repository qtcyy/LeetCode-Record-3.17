from typing import List


class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        """
        f[i][j]
        第i周结束停留在j城市的最大休息天数
        u->j
        f[i][j]=max(f[i-1][j],f[i-1][u])+days[j][i]
        """
        n, m = len(flights), len(days[0])
        f = [[-1] * (m + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i in range(m):
            for j in range(n):
                # f[i + 1][j] = f[i][j] + days[j][i]
                for k in range(n):
                    if (flights[j][k] or j == k) and f[i][k] >= 0:
                        f[i + 1][j] = max(f[i + 1][j], f[i][k] + days[j][i])
        return max(f[-1])


class Solution2:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        """
        倒推
        """
        n, m = len(flights), len(days[0])
        f = [[0] * n for _ in range(m + 1)]
        for week in range(m - 1, -1, -1):
            for i in range(n):
                for j in range(n):
                    if i == j or flights[i][j]:
                        f[week][i] = max(f[week][i], f[week + 1][j] + days[j][week])
        return f[0][0]


def main():
    flights = [[0, 1, 1], [1, 0, 1], [1, 1, 0]]
    days = [[1, 3, 1], [6, 0, 3], [3, 3, 3]]
    sol = Solution2()
    print(sol.maxVacationDays(flights, days))


main()
