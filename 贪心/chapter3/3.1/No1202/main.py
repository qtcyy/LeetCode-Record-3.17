from typing import List


class MergeSet:
    def __init__(self, n: int) -> None:
        self.f = [x for x in range(n)]

    def find(self, x: int) -> int:
        if self.f[x] == x:
            return x
        self.f[x] = self.find(self.f[x])
        return self.f[x]

    def merge(self, x: int, y: int) -> None:
        x, y = self.find(x), self.find(y)
        if x != y:
            self.f[x] = y


class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        n = len(s)
        st = MergeSet(n)
        for p in pairs:
            st.merge(p[0], p[1])
        rec: dict[int, str] = dict()
        idx: dict[int, list] = dict()
        for i in range(n):
            x = st.find(i)
            if x in idx:
                idx[x].append(i)
            else:
                idx[x] = [i]
            if x in rec:
                rec[x] += s[i]
            else:
                rec[x] = s[i]
        print(rec)
        print(idx)

        for x in rec:
            arr = sorted(rec[x])
            for i, pos in enumerate(idx[x]):
                s = s[:pos] + arr[i] + s[pos + 1 :]

        return s


def main():
    s = "dcab"
    pairs = [[0, 3], [1, 2], [0, 2]]
    sol = Solution()
    print(sol.smallestStringWithSwaps(s, pairs))


main()
