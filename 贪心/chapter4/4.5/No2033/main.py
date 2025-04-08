from typing import List


class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        a = []
        for row in grid:
            for v in row:
                a.append(v)
        a.sort()
        n = len(a)
        base = a[n // 2]
        ans = 0
        for v in a:
            delta = abs(v - base)
            if delta % x != 0:
                return -1
            ans += delta // x
        return ans


def main():
    grid = [[2, 4], [6, 8]]
    x = 2
    sol = Solution()
    print(sol.minOperations(grid, x))


main()
