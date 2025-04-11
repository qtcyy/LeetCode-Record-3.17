mx = lambda x, y: x if x > y else y


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        """
        最长相同子序列
        """
        n, m = len(word1), len(word2)
        f = [[0] * (m + 1) for _ in range(n + 1)]
        for i, x in enumerate(word1):
            for j, y in enumerate(word2):
                if x == y:
                    f[i + 1][j + 1] = f[i][j] + 1
                else:
                    f[i + 1][j + 1] = mx(f[i + 1][j], f[i][j + 1])
        maxn = f[-1][-1]
        return n + m - maxn * 2


def main():
    word1 = "sea"
    word2 = "eat"
    sol = Solution()
    print(sol.minDistance(word1, word2))


main()
