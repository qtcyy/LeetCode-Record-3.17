class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fib = [1, 1]
        while fib[-1] <= k:
            cur = fib[-1] + fib[-2]
            fib.append(cur)
        n = len(fib)
        ans = 0
        for i in range(n - 1, -1, -1):
            if k >= fib[i]:
                k -= fib[i]
                ans += 1
        return ans


def main():
    k = 19
    sol = Solution()
    print(sol.findMinFibonacciNumbers(k))


main()
