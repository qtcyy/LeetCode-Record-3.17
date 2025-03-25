class Solution:
    def reverseParentheses(self, s: str) -> str:
        st = []
        n = len(s)
        for i in range(n):
            if len(st) > 0 and s[i] == ")":
                s[st[-1] + 1 : i] = s[i - 1 : st[-1] : -1]
            elif s[i] == "(":
                st.append(i)


def main():
    s = "(ed(et(oc))el)"
    sol = Solution()
    print(sol.reverseParentheses(s))


main()
