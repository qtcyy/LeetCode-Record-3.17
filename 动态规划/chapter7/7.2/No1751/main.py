from bisect import bisect_left
from typing import List


class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n = len(events)
        events.sort(key=lambda e: e[1])
        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(n):
            p = bisect_left(events, events[i][0], key=lambda e: e[1])
            for j in range(1, k + 1):
                f[i + 1][j] = max(f[i][j], f[p][j - 1] + events[i][2])
        return f[-1][-1]


def main():
    events = [[1, 2, 4], [3, 4, 3], [2, 3, 1]]
    k = 2
    sol = Solution()
    print(sol.maxValue(events, k))


main()
