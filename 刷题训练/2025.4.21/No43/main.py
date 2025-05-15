class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        return str(int(num1) * int(num2))


def main():
    sol = Solution()
    num1 = "123"
    num2 = "456"
    print(sol.multiply(num1, num2))


main()
