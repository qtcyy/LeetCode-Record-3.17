from functools import cache


class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        s = str(n)

        @cache
        def dfs(i: int, mask: int, is_limit: bool, is_num: bool) -> int:
            if i == len(s):
                return int(is_num)
            res = 0
            if not is_num:
                res = dfs(i + 1, mask, False, False)
            up = int(s[i]) if is_limit else 9
            for d in range(1 - int(is_num), up + 1):
                if mask >> d & 1 == 0:
                    res += dfs(i + 1, mask | (1 << d), is_limit and d == up, True)
            return res

        return dfs(0, 0, True, False)


def main():
    n = 135
    sol = Solution()
    print(sol.countSpecialNumbers(n))


main()
