from typing import List


class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        """
        f[i][j] 以nums[i]结尾有j个数字与下一个不相等
        """
        n = len(nums)
        f = [[-1] * 51 for _ in range(n)]
        ans = 0

        for i in range(n):
            f[i][0] = 1
            for l in range(k + 1):
                for j in range(i):
                    add = 1 if nums[i] != nums[j] else 0
                    if l >= add and f[j][l - add] != -1:
                        f[i][l] = max(f[i][l], f[j][l - add] + 1)
                ans = max(ans, f[i][l])
        return ans


def main():
    nums = [1, 2, 1, 1, 3]
    k = 2
    sol = Solution()
    print(sol.maximumLength(nums, k))


main()
