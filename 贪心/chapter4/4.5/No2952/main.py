from typing import List


class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        s, ans = 1, 0
        i = 0
        while s <= target:
            if i < len(coins) and coins[i] <= s:
                s += coins[i]
                i += 1
            else:
                s *= 2
                ans += 1
        return ans


def main():
    coins = [1, 4, 10]
    target = 19
    sol = Solution()
    print(sol.minimumAddedCoins(coins, target))


main()
