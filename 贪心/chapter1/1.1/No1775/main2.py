from typing import Counter, List


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        if 6 * len(nums1) < len(nums2) or 6 * len(nums2) < len(nums1):
            return -1
        d = sum(nums2) - sum(nums1)
        if d < 0:
            d = -d
            nums1, nums2 = nums2, nums1
        ans = 0
        cnt = Counter(6 - x for x in nums1) + Counter(x - 1 for x in nums2)
        for i in range(5, 0, -1):
            if i * cnt[i] >= d:
                return ans + (d + i - 1) // i
            ans += cnt[i]
            d -= i * cnt[i]


def main():
    nums1 = [1, 2, 3, 4, 5, 6]
    nums2 = [1, 1, 2, 2, 2, 2]
    sol = Solution()
    print(sol.minOperations(nums1, nums2))


main()
