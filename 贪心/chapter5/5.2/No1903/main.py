class Solution:
    def largestOddNumber(self, num: str) -> str:
        n = len(num)
        a = list(num)
        pos = 0
        for i in range(n - 1, -1, -1):
            if int(a[i]) & 1:
                pos = i
                break
        if int(a[pos]) & 1 == 0:
            return ""
        return num[: pos + 1]


def main():
    num = "35427"
    sol = Solution()
    print(sol.largestOddNumber(num))


main()
