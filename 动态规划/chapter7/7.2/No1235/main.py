from bisect import bisect_left, bisect_right
from typing import List


class Solution:
    def jobScheduling(
        self, startTime: List[int], endTime: List[int], profit: List[int]
    ) -> int:
        n = len(profit)
        f = [0] * n
        f[0] = profit[0]
        arr = list(zip(endTime, startTime, profit))
        arr.sort()
        endTime.sort()
        for i in range(1, n):
            idx = bisect_right(endTime, arr[i][1]) - 1
            f[i] = max(f[i - 1], f[idx] + arr[i][2])
        return f[-1]


def main():
    startTime = [1, 2, 3, 3]
    endTime = [3, 4, 5, 6]
    profit = [50, 10, 40, 70]
    sol = Solution()
    print(sol.jobScheduling(startTime, endTime, profit))


main()
