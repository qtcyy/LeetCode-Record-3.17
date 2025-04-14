from functools import cache


class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        s = str(n)

        @cache
        def dfs(i: int, mask: int, cnt: int, is_limit: bool, is_num: bool) -> int:
            if i == len(s):
                return int(cnt >= 1)
            res = 0
            if not is_num:
                res = dfs(i + 1, mask, cnt, False, False)
            up = int(s[i]) if is_limit else 9
            for d in range(1 - int(is_num), up + 1):
                res += dfs(
                    i + 1,
                    mask | (1 << d),
                    cnt + (mask >> d & 1),
                    is_limit and d == up,
                    True,
                )
            return res

        return dfs(0, 0, 0, True, False)


def main():
    n = 1000
    sol = Solution()
    print(sol.numDupDigitsAtMostN(1000))


main()
