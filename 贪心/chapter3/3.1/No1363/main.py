from math import inf
from typing import List


class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        digits.sort()
        n = len(digits)
        f = [[0, -inf, -inf] for _ in range(n + 1)]
        for i in range(n):
            for j in range(3):
                f[i + 1][j] = max(f[i][j], f[i][(j - digits[i]) % 3] + 1)
        if f[-1][0] == 0:
            return ""
        res = ""
        j = 0
        for i in range(n, -1, -1):
            if f[i][j] == f[i - 1][(j - digits[i - 1]) % 3] + 1:
                res += str(digits[i - 1])
                j = (j - digits[i - 1]) % 3
        if res[0] == "0":
            return "0"
        return res


def main():
    digits = [8, 6, 7, 1, 0]
    sol = Solution()
    print(sol.largestMultipleOfThree(digits))


main()
