from functools import cache


class Solution:
    def findIntegers(self, n: int) -> int:
        m = n.bit_length() - 1

        @cache
        def dfs(i: int, pre1: bool, is_limit: bool) -> int:
            if i < 0:
                return 1
            res = 0
            up = n >> i & 1 if is_limit else 1
            res = dfs(i - 1, False, is_limit and up == 0)
            if not pre1 and up == 1:
                res += dfs(i - 1, True, is_limit)
            return res

        return dfs(m, False, True)


def main():
    n = 5
    sol = Solution()
    print(sol.findIntegers(n))


main()
