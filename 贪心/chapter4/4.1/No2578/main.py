class Solution:
    def splitNum(self, num: int) -> int:
        a = list(str(num))
        a.sort()
        num1, num2 = int("".join(a[::2])), int("".join(a[1::2]))
        return num1 + num2


def main():
    num = 687
    sol = Solution()
    print(sol.splitNum(num))


main()
