from functools import cache


class Solution:
    def numberOf2sInRange(self, n: int) -> int:
        s = str(n)

        @cache
        def dfs(i: int, cnt: int, is_limit: bool, is_num: bool) -> int:
            if i == len(s):
                return cnt if is_num else 0
            res = 0
            if not is_num:
                res = dfs(i + 1, cnt, False, False)
            up = int(s[i]) if is_limit else 9
            for d in range(1 - int(is_num), up + 1):
                res += dfs(i + 1, cnt + (d == 2), is_limit and d == up, True)
            return res

        return dfs(0, 0, True, False)


def main():
    n = 25
    sol = Solution()
    print(sol.numberOf2sInRange(n))


main()
