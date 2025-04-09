mx = lambda x, y: x if x > y else y


class Solution:
    def minPartitions(self, n: str) -> int:
        ans = 0
        for c in n:
            ans = mx(ans, int(c))
        return ans


def main():
    n = "27346209830709182346"
    sol = Solution()
    print(sol.minPartitions(n))


main()
