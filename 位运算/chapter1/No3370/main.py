class Solution:
    def smallestNumber(self, n: int) -> int:
        res = 1
        while n:
            n >>= 1
            res <<= 1
        return res - 1


def main():
    n = 10
    sol = Solution()
    print(sol.smallestNumber(n))


main()
