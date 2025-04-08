from typing import List


class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        coins.sort()
        s = 0
        for c in coins:
            if c > s + 1:
                break
            s += c
        return s + 1


def main():
    coins = [1, 1, 1, 4]
    sol = Solution()
    print(sol.getMaximumConsecutive(coins))


main()
