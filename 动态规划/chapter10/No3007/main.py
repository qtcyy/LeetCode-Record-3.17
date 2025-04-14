from functools import cache


class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        def check(mid: int) -> bool:
            m = mid.bit_length() - 1

            @cache
            def dfs(i: int, cnt: int, is_limit: bool, is_num: bool) -> int:
                if i < 0:
                    return cnt if is_num else 0
                res = 0
                up = mid >> i & 1 if is_limit else 1
                if not is_num:
                    res = dfs(i - 1, cnt, is_limit and up == 0, False)
                if up == 1:
                    res += dfs(
                        i - 1, cnt + ((i + 1) % x == 0), is_limit and up == 1, True
                    )
                return res

            val = dfs(m, 0, True, False)
            print(val)
            return val <= k

        l, r = -1, k + 1
        while l + 1 < r:
            mid = (l + r) >> 1
            if check(mid):
                l = mid
            else:
                r = mid

        return l


def main():
    k = 7
    x = 2
    sol = Solution()
    print(sol.findMaximumNumber(k, x))


main()
