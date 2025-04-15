class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD = 10**9 + 7
        f = [0] * n
        f[0] = 1
        cnt = 0
        for i, v in enumerate(f):
            if i + delay >= n:
                cnt = (cnt + v) % MOD
            for j in range(i + delay, min(i + forget, n)):
                f[j] = (f[j] + v) % MOD
        return f[-1] + cnt


def main():
    n = 4
    delay = 1
    forget = 3
    sol = Solution()
    print(sol.peopleAwareOfSecret(n, delay, forget))


main()
