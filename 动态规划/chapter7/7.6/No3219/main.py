from typing import List


class Solution:
    def minimumCost(
        self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]
    ) -> int:
        horizontalCut.sort()
        verticalCut.sort()
        ans = i = j = 0
        for _ in range(m + n - 2):
            if j == n - 1 or i < m - 1 and horizontalCut[i] < verticalCut[j]:
                ans += horizontalCut[i] * (n - j)
                i += 1
            else:
                ans += verticalCut[j] * (m - i)
                j += 1
        return ans


def main():
    m = 3
    n = 2
    horizontalCut = [1, 3]
    verticalCut = [5]
    sol = Solution()
    print(sol.minimumCost(m, n, horizontalCut, verticalCut))


main()
