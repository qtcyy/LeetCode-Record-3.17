from typing import List


class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums1)
        nums1.sort()
        idx = sorted(range(n), key=lambda i: nums2[i])
        ans = [0] * n
        left, right = 0, n - 1
        for x in nums1:
            if x > nums2[idx[left]]:
                ans[idx[left]] = x
                left += 1
            else:
                ans[idx[right]] = x
                right -= 1

        return ansg


def main():
    nums1 = [12, 24, 8, 32]
    nums2 = [13, 25, 32, 11]
    sol = Solution()
    print(sol.advantageCount(nums1, nums2))


main()
