from typing import List


class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        mx = max(damage)
        if mx > armor:
            return sum(damage) - armor + 1
        else:
            return sum(damage) - mx + 1


def main():
    damage = [2, 5, 3, 4]
    armor = 7
    sol = Solution()
    print(sol.minimumHealth(damage, armor))


main()
