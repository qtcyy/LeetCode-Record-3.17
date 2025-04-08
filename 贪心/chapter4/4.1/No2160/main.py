class Solution:
    def minimumSum(self, num: int) -> int:
        s = str(num)
        a = list(s)
        a.sort()
        num1, num2 = int("".join(a[::2])), int("".join(a[1::2]))

        return num1 + num2


def main():
    num = 2932
    sol = Solution()
    print(sol.minimumSum(num))


main()
