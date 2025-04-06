from math import sqrt
from typing import List


class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned = sorted(set(banned)) + [n + 1]
        pre = [0]
        for i, b in enumerate(banned):
            pre.append(pre[-1] + b)
            if banned[i] * (banned[i] + 1) // 2 - pre[-1] > maxSum:
                break
        else:
            return banned[i] - i - 1

        x = maxSum + pre[i]

        return int((-1 + sqrt(1 + (1 + 8 * x))) // 2) - i


def main():
    banned = [4, 3, 5, 6]
    n = 7
    maxSum = 18
    sol = Solution()
    print(sol.maxCount(banned, n, maxSum))


main()
