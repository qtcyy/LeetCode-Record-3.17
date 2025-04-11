class Solution:
    def minChanges(self, n: int, k: int) -> int:
        if n < k:
            return -1
        ans = 0
        while n:

            if n & 1 == 0 and k & 1 == 1:
                return -1
            if n & 1 == 1 and k & 1 == 0:
                ans += 1
            n >>= 1
            k >>= 1
        return ans


def main():
    n = 13
    k = 4
    sol = Solution()
    print(sol.minChanges(n, k))


main()
