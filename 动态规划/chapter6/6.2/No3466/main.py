from typing import List


class Solution:
    def maxCoins(self, lane1: List[int], lane2: List[int]) -> int:
        n = len(lane1)
        inf = int(1 << 62)
        f = [[0] * 3 for _ in range(n + 1)]
        f[0] = [0, -inf, -inf]
        ans = -inf
        for i in range(n):
            f[i + 1][0] = max(lane1[i], f[i][0] + lane1[i])
            f[i + 1][1] = max(f[i][1] + lane2[i], f[i][0] + lane2[i], lane2[i])
            f[i + 1][2] = max(f[i][2] + lane1[i], f[i][1] + lane1[i], lane1[i])
            ans = max(ans, max(f[i + 1]))
        return ans


def main():
    lane1 = [1, -2, -10, 3]
    lane2 = [-5, 10, 0, 1]
    sol = Solution()
    print(sol.maxCoins(lane1, lane2))


main()
