class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        MOD = 1_000_000_007
        k = (1 << p) - 1
        return k * pow(k - 1, k >> 1, MOD) % MOD


def main():
    p = 3
    sol = Solution()
    print(sol.minNonZeroProduct(p))


main()
