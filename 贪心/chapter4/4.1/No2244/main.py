from collections import Counter
from typing import List


class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks)
        if 1 in cnt.values():
            return -1
        ans = 0
        for x in cnt.values():
            if x % 3 == 1:
                ans += x // 3 - 1 + 2
            else:
                ans += x // 3 + (x % 3) // 2
        return ans


def main():
    tasks = [2, 2, 3, 3, 2, 4, 4, 4, 4, 4]
    sol = Solution()
    print(sol.minimumRounds(tasks))


main()
