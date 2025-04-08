from typing import List


class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        a = sorted(zip(reward1, reward2), key=lambda x: x[1] - x[0])
        ans = 0
        n = len(a)
        for i in range(k):
            ans += a[i][0]
        for i in range(k, n):
            ans += a[i][1]
        return ans


def main():
    reward1 = [1, 1, 3, 4]
    reward2 = [4, 4, 1, 1]
    k = 2
    sol = Solution()
    print(sol.miceAndCheese(reward1, reward2, k))


main()
