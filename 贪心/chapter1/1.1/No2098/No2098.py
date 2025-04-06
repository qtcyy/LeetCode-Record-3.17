from typing import List


class Solution:
    def largestEvenSum(self, nums: List[int], k: int) -> int:
        odd_pre, even_pre = [0], [0]
        nums.sort(reverse=True)
        for x in nums:
            if x & 1:
                odd_pre.append(odd_pre[-1] + x)
            else:
                even_pre.append(even_pre[-1] + x)
        ans = -1
        n, m = len(odd_pre), len(even_pre)
        for i in range(0, n, 2):
            if 0 <= k - i < m:
                ans = max(ans, odd_pre[i] + even_pre[k - i])
        return ans


def main():
    nums = [4, 1, 5, 3, 1]
    k = 3
    sol = Solution()
    print(sol.largestEvenSum(nums, k))


if __name__ == "__main__":
    main()
