from bisect import bisect_left
from typing import List


class Solution2:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        a = [(r, l, weight, i) for i, (l, r, weight) in enumerate(intervals)]
        a.sort(key=lambda t: t[0])  # 按照右端点排序
        f = [[(0, []) for _ in range(5)] for _ in range(len(intervals) + 1)]
        for i, (r, l, weight, idx) in enumerate(a):
            k = bisect_left(a, (l,), hi=i)  # hi=i 表示二分上界为 i（默认为 n）
            for j in range(1, 5):
                # 为什么是 f[k] 不是 f[k+1]：上面算的是 >= l，-1 后得到 < l，但由于还要 +1，抵消了
                s2, id2 = f[k][j - 1]
                # 注意这里是减去 weight，这样取 min 后相当于计算的是最大和
                f[i + 1][j] = min(f[i][j], (s2 - weight, sorted(id2 + [idx])))
        return f[-1][4][1]


class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        a = [(r, l, weight, i) for i, (l, r, weight) in enumerate(intervals)]
        a.sort(key=lambda e: e[0])
        f = [[(0, []) for _ in range(5)] for _ in range(len(intervals) + 1)]
        for i, (_, l, weight, idx) in enumerate(a):
            k = bisect_left(a, (l,), hi=i)
            for j in range(1, 5):
                s2, id2 = f[k][j - 1]
                f[i + 1][j] = min(f[i][j], (s2 - weight, sorted(id2 + [idx])))
        return f[-1][4][1]


def main():
    intervals = [
        [5, 8, 1],
        [6, 7, 7],
        [4, 7, 3],
        [9, 10, 6],
        [7, 8, 2],
        [11, 14, 3],
        [3, 5, 5],
    ]
    sol = Solution()
    print(sol.maximumWeight(intervals))


main()
