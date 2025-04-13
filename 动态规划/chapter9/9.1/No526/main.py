class Solution:
    def countArrangement(self, n: int) -> int:
        f = [0] * (1 << n)
        f[0] = 1
        for s in range(1, 1 << n):
            i = s.bit_count()
            for j in range(1, n + 1):
                if s >> (j - 1) & 1 and (i % j == 0 or j % i == 0):
                    f[s] += f[s ^ (1 << (j - 1))]
        return f[-1]


def main():
    n = 2
    sol = Solution()
    print(sol.countArrangement(n))


main()
