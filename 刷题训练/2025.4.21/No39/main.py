from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        path = []

        def dfs(tot: int) -> None:
            if tot == target:
                ans.append(path.copy())
                return
            elif tot > target:
                return

            for x in candidates:
                if path and x < path[-1]:
                    continue
                path.append(x)
                dfs(tot + x)
                path.pop()

        dfs(0)
        return ans


def main():
    candidates = [2, 3, 5]
    target = 8
    sol = Solution()
    print(sol.combinationSum(candidates, target))


main()
