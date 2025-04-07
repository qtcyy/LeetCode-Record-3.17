from collections import Counter
from typing import Dict, List


class MergeSet:
    def __init__(self, n: int) -> None:
        self.f = [x for x in range(n)]

    def find(self, x: int) -> int:
        if self.f[x] == x:
            return x
        self.f[x] = self.find(self.f[x])
        return self.f[x]

    def merge(self, x: int, y: int) -> None:
        x = self.find(x)
        y = self.find(y)
        if x != y:
            self.f[x] = y


class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        cnt: Dict[int, List[int]] = dict()
        for i, x in enumerate(nums):
            if x in cnt:
                cnt[x].append(i)
            else:
                cnt[x] = [i]

        items = sorted(cnt.items())
        m = len(items)
        st = MergeSet(n)
        for i in range(m):
            base = items[i][1]
            for x in items[i][1]:
                st.merge(base[0], x)
        for i in range(m - 1):
            if items[i + 1][0] - items[i][0] <= limit:
                st.merge(items[i][1][0], items[i + 1][1][0])

        rec: List[List[int]] = [[] for _ in range(n)]
        pos: List[List[int]] = [[] for _ in range(n)]
        for i in range(n):
            base = st.find(i)
            rec[base].append(nums[i])
            pos[base].append(i)

        ans = [0] * n
        for i in range(n):
            if not rec[i]:
                continue
            base = st.find(i)
            rec[base].sort()
            for i, x in enumerate(pos[base]):
                ans[x] = rec[base][i]

        return ans


class Solution2:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        a = sorted(zip(nums, range(n)))
        ans = [0] * n
        i = 0
        while i < n:
            st = i
            i += 1
            while i < n and a[i][0] - a[i - 1][0] <= limit:
                i += 1
            sub = a[st:i]
            sub_idx = sorted(i for _, i in sub)
            for j, (x, _) in zip(sub_idx, sub):
                ans[j] = x

        return ans


def main():
    nums = [1, 7, 6, 18, 2, 1]
    limit = 3
    sol = Solution2()
    print(sol.lexicographicallySmallestArray(nums, limit))


main()
