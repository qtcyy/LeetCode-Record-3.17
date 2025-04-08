from typing import List


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda x: x[0] - x[1])
        n = len(costs)
        ans = 0
        for i in range(n // 2):
            ans += costs[i][0]
        for j in range(n // 2, n):
            ans += costs[j][1]
        return ans


def main():
    costs = [
        [515, 563],
        [451, 713],
        [537, 709],
        [343, 819],
        [855, 779],
        [457, 60],
        [650, 359],
        [631, 42],
    ]
    sol = Solution()
    print(sol.twoCitySchedCost(costs))


main()
