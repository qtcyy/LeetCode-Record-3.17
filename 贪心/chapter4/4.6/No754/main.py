class Solution:
    def reachNumber(self, target: int) -> int:
        s, ans = 0, 0
        target = abs(target)
        while s < target or (target - s) % 2:
            ans += 1
            s += ans
        return ans


def main():
    target = 3
    sol = Solution()
    print(sol.reachNumber(target))


main()
