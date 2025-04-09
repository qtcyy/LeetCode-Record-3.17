from typing import List


class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n = len(nums)
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] + nums[i]
        ans = 0
        for i in range(n - 1):
            sum1 = pre[i + 1]
            sum2 = pre[-1] - pre[i + 1]
            if (sum1 - sum2) % 2 == 0:
                ans += 1
        return ans


def main():
    nums = [10, 10, 3, 7, 6]
    sol = Solution()
    print(sol.countPartitions(nums))


main()
