class Solution:
    def nextPalindrome(self, num: str) -> str:
        n = len(num) // 2
        num_list = list(num)
        for i in range(n - 1, 0, -1):
            if num_list[i - 1] < num_list[i]:
                num_list[i], num_list[i - 1] = num_list[i - 1], num_list[i]
                num_list[n - i - 1], num_list[n - i] = (
                    num_list[n - i],
                    num_list[n - i - 1],
                )
                break
        ans = "".join(num_list)
        return ans if ans != num else ""


def main():
    num = "45544554"
    sol = Solution()
    print(sol.nextPalindrome(num))


main()
