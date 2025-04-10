from typing import List


class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        n = len(energyDrinkA)
        f = [[0] * 2 for _ in range(n + 1)]
        for i in range(n):
            f[i + 1][0] = max(f[i][0] + energyDrinkA[i], f[i][1])
            f[i + 1][1] = max(f[i][1] + energyDrinkB[i], f[i][0])
        return max(f[-1])


def main():
    energyDrinkA = [1, 3, 1]
    energyDrinkB = [3, 1, 1]
    sol = Solution()
    print(sol.maxEnergyBoost(energyDrinkA, energyDrinkB))


main()
