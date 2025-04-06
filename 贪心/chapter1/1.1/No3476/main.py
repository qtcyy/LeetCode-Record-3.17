from collections import Counter
from typing import List


class Solution:
    def maxProfit(self, workers: List[int], tasks: List[List[int]]) -> int:
        st = Counter(workers)
        tasks.sort(key=lambda x: -x[1])
        n = len(tasks)
        vis = [False] * n
        ans = 0
        for i, (skill, val) in enumerate(tasks):
            if skill in st:
                ans += val
                vis[i] = True
                st[skill] -= 1
                if st[skill] <= 0:
                    st.pop(skill)
        for i, (_, val) in enumerate(tasks):
            if not vis[i]:
                ans += val
                break
        return ans


def main():
    workers = [1, 2, 3, 4, 5]
    tasks = [[1, 100], [2, 400], [3, 100], [3, 400]]
    sol = Solution()
    print(sol.maxProfit(workers, tasks))


main()
