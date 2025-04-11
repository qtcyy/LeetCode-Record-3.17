class Solution:
    def minimumDistance(self, word: str) -> int:
        n = len(word)
        INF = 2**30
        f = [[[INF] * 26 for _ in range(26)] for __ in range(n)]
        cur = ord(word[0]) - 65
        for i in range(26):
            f[0][cur][i] = f[0][i][cur] = 0

        def dist(x, y) -> int:
            x1, y1 = x // 6, x % 6
            x2, y2 = y // 6, y % 6
            return abs(x1 - x2) + abs(y1 - y2)

        for i in range(1, n):
            pre, cur = ord(word[i - 1]) - 65, ord(word[i]) - 65
            d = dist(pre, cur)
            for j in range(26):
                f[i][cur][j] = min(f[i][cur][j], f[i - 1][pre][j] + d)
                f[i][j][cur] = min(f[i][j][cur], f[i - 1][j][pre] + d)
                if j == pre:
                    for k in range(26):
                        d2 = dist(cur, k)
                        f[i][cur][j] = min(f[i][cur][j], f[i - 1][k][j] + d2)
                        f[i][j][cur] = min(f[i][j][cur], f[i - 1][j][k] + d2)
        return min(min(f[-1][x]) for x in range(26))


def main():
    word = "HAPPY"
    sol = Solution()
    print(sol.minimumDistance(word))


main()
