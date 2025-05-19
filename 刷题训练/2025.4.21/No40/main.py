from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        candidates.sort()
        path = []
        ans = []

        def dfs(i: int, tot: int) -> None:
            if tot == target:
                ans.append(path.copy())
                return
            elif tot > target:
                return

            for j in range(i, n):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                path.append(candidates[j])
                dfs(j + 1, tot + candidates[j])
                path.pop()

        dfs(0, 0)
        return ans


def main():
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    sol = Solution()
    print(sol.combinationSum2(candidates, target))


main()
