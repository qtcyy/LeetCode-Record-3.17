class Solution:
    def addMinimum(self, word: str) -> int:
        st = []
        a = list(word)
        n = len(a)
        i = 0
        base = list("abc")
        for c in base:
            st.append(c)
        while i < n:
            if (ord(st[-1]) - 64) % 3 == ord(a[i]) - 65:
                st.append(a[i])
                i += 1
            else:
                st.append(chr((ord(st[-1]) - 64) % 3 + 65))
        return len(st)


def main():
    word = "aaa"
    sol = Solution()
    print(sol.addMinimum(word))


main()
