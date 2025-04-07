from collections import Counter
from string import ascii_lowercase


class Solution:
    def robotWithString(self, s: str) -> str:
        min = 0
        st = []
        cnt = Counter(s)
        ans = []
        for c in s:
            cnt[c] -= 1
            while min < 25 and cnt[ascii_lowercase[min]] == 0:
                min += 1
            st.append(c)
            while st and st[-1] <= ascii_lowercase[min]:
                ans.append(st[-1])
                st.pop()
        return "".join(ans)


def main():
    sol = Solution()
    s = "bdda"
    print(sol.robotWithString(s))


main()
