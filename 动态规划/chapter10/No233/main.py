from functools import cache


class Solution:
    def countDigitOne(self, n: int) -> int:
        s = str(n)

        @cache
        def dfs(i: int, cnt: int, is_limit: bool) -> int:
            if i == len(s):
                return cnt
            res = 0
            up = int(s[i]) if is_limit else 9
            for d in range(up + 1):
                res += dfs(i + 1, cnt + (d == 1), is_limit and d == up)
            return res

        return dfs(0, 0, True)


def main():
    n = 13
    sol = Solution()
    print(sol.countDigitOne(n))


main()
