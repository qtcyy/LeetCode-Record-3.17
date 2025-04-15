from functools import cache


class Solution:
    def countNumbers(self, l: str, r: str, b: int) -> int:
        n = len(r)
        l = "0" * (n - len(l)) + l
        MOD = 10**9 + 7

        def check(x: int) -> bool:
            digits = ""
            while x:
                digits = str(x % b) + digits
                x //= b
            if len(digits) <= 1:
                return True
            for i in range(1, len(digits)):
                if digits[i - 1] > digits[i]:
                    return False
            return True

        @cache
        def dfs(
            i: int, last: int, limit_low: bool, limit_high: bool, is_num: bool
        ) -> int:
            if i == n:
                return 1
            res = 0
            if not is_num and l[i] == "0":
                res = dfs(i + 1, 0, True, False, False)
            lo = int(l[i]) if limit_low else 0
            hi = int(r[i]) if limit_high else 9
            d0 = 0 if is_num else 1
            for d in range(max(d0, lo), hi + 1):
                if is_num:
                    if check(last * 10 + d):
                        res = (
                            res
                            + dfs(
                                i + 1,
                                d,
                                limit_low and d == lo,
                                limit_high and d == hi,
                                True,
                            )
                        ) % MOD
                else:
                    if check(d):
                        res = (
                            res
                            + dfs(
                                i + 1,
                                d,
                                limit_low and d == lo,
                                limit_high and d == hi,
                                True,
                            )
                        ) % MOD
            return res

        return dfs(0, 0, True, True, False)


def main():
    l = "23"
    r = "28"
    b = 8
    sol = Solution()
    print(sol.countNumbers(l, r, b))


main()
