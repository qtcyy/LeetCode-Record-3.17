from collections import Counter
from typing import List


class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        cnt = Counter(c % 2 for c in position)
        return min(cnt[0], cnt[1])


def main():
    position = [2, 2, 2, 3, 3]
    sol = Solution()
    print(sol.minCostToMoveChips(position))


main()
