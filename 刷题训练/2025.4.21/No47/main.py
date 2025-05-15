from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        path = [0] * n
        on_path = [False] * n
        ans = []

        def dfs(i: int) -> None:
            if i == n:
                ans.append(path.copy())
                return
            for j, on in enumerate(on_path):
                if on or j > 0 and nums[j] == nums[j - 1] and not on_path[j - 1]:
                    continue
                path[i] = nums[j]
                on_path[j] = True
                dfs(i + 1)
                on_path[j] = False

        dfs(0)
        return ans


def main():
    nums = [1, 1, 2]
    sol = Solution()
    print(sol.permuteUnique(nums))


main()
