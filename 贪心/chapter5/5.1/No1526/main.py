from typing import List


class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        target.insert(len(target), 0)
        top = target[0]
        n = len(target)
        i = 0
        ans = 0
        while i < n:
            while i + 1 < n and target[i + 1] < target[i]:
                i += 1
            ans += top - target[i]
            while i + 1 < n and target[i + 1] > target[i]:
                i += 1
            top = target[i]
            i += 1
        return ans


def main():
    target = [3, 1, 5, 4, 2]
    sol = Solution()
    print(sol.minNumberOperations(target))


main()
