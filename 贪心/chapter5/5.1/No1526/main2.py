from typing import List


class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        """
        差分数组做法
        """
        n = len(target)
        rec = [0] * n
        rec[0] = target[0]
        for i in range(1, n):
            rec[i] = target[i] - target[i - 1]
        return sum(max(0, c) for c in rec)


def main():
    target = [3, 1, 5, 4, 2]
    sol = Solution()
    print(sol.minNumberOperations(target))


main()
