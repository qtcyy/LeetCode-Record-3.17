from typing import List


class Std:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        indices = {x: i for i, x in enumerate(arr)}
        ans, n = 0, len(arr)
        dp = [[0] * n for _ in range(n)]
        for i, x in enumerate(arr):
            for j in range(n - 1, -1, -1):
                if arr[j] * 2 <= x:
                    break
                if x - arr[j] in indices:
                    k = indices[x - arr[j]]
                    dp[j][i] = max(dp[k][j] + 1, 3)
                    ans = max(ans, dp[j][i])
        return ans


class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        dic = {x: i for i, x in enumerate(arr)}
        ans, n = 0, len(arr)
        f = [[0] * n for _ in range(n)]
        for i, x in enumerate(arr):
            for j in range(n - 1, -1, -1):
                if arr[j] * 2 <= x:
                    break
                if x - arr[j] in dic:
                    k = dic[x - arr[j]]
                    f[j][i] = max(f[k][j] + 1, 3)
                    ans = max(ans, f[j][i])
        return ans


def main():
    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    sol = Solution()
    print(sol.lenLongestFibSubseq(arr))


main()
