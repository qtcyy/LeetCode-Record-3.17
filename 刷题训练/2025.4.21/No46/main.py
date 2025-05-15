from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        path = [0] * n
        on_path = [False] * n
        ans = []

        def dfs(i: int) -> None:
            if i == n:
                ans.append(path.copy())
                return
            for j, on in enumerate(on_path):
                if not on:
                    path[i] = nums[j]
                    on_path[j] = True
                    dfs(i + 1)
                    on_path[j] = False

        dfs(0)
        return ans


def main():
    nums = [1, 2, 3]
    sol = Solution()
    print(sol.permute(nums))


main()
