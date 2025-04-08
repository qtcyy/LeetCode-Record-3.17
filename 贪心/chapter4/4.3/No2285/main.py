from typing import List


class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        deg = [0] * n
        for road in roads:
            deg[road[0]] += 1
            deg[road[1]] += 1
        deg.sort()
        return sum(d * i for d, i in enumerate(deg, 1))


def main():
    sol = Solution()
    n = 5
    roads = [[0, 1], [1, 2], [2, 3], [0, 2], [1, 3], [2, 4]]
    print(sol.maximumImportance(n, roads))


main()
