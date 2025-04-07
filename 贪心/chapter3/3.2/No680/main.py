class Solution:
    def validPalindrome(self, s: str) -> bool:
        """
        删两次
        """
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                break
            i += 1
            j -= 1
        if i >= j:
            return True

        flag = True
        # 删i
        a = s[:i] + s[i + 1 :]
        m = len(a)
        for idx in range(m // 2):
            if a[idx] != a[m - idx - 1]:
                flag = False
                break
        if flag:
            return True
        # 删j
        flag = True
        a = s[:j] + s[j + 1 :]
        for idx in range(m // 2):
            if a[idx] != a[m - idx - 1]:
                flag = False
                break
        return flag


def main():
    s = "abca"
    sol = Solution()
    print(sol.validPalindrome(s))


main()
