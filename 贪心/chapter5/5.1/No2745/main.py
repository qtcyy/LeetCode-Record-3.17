class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        if x == y:
            return x * 4 + z * 2
        a = min(x, y)
        return (a + a + 1 + z) * 2


def main():
    x = 2
    y = 5
    z = 1
    sol = Solution()
    print(sol.longestString(x, y, z))


main()
