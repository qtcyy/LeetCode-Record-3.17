from typing import List


class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        n = len(cost)
        if n < 3:
            return sum(cost)
        cost.sort(reverse=True)
        ans = 0
        for i in range(0, n, 3):
            ans += cost[i] + cost[i + 1]
        rest = n % 3
        for i in range(1, rest + 1):
            ans += cost[-i - 1]
        return ans


def main():
    cost = [6, 5, 7, 9, 2, 2]
    sol = Solution()
    print(sol.minimumCost(cost))


main()
