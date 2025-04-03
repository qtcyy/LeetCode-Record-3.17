class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s1 = sorted(s1)
        s2 = sorted(s2)
        flag, flag2 = True, True
        for i, ch in enumerate(s1):
            if ch < s2[i]:
                flag = False
                break
        for i, ch in enumerate(s2):
            if ch < s1[i]:
                flag2 = False
                break
        if not flag and not flag2:
            return False
        return Truegi


def main():
    s1 = "abc"
    s2 = "xya"
    sol = Solution()
    print(sol.checkIfCanBreak(s1, s2))


main()
