from typing import List


class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        a = []
        for row in values:
            for x in row:
                a.append(x)
        a.sort()
        ans = 0
        for i, x in enumerate(a, 1):
            ans += i * x
        return ans


def main():
    sol = Solution()
    values = [[8, 5, 2], [6, 4, 1], [9, 7, 3]]
    print(sol.maxSpending(values))


main()
