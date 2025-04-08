from math import isqrt


class Solution:
    def minOperations(self, k: int) -> int:
        """
        x+(k-1)/(1+x)
        x+1 + (k-1)/(x+1) - 1 >=2sqrt(k-1) -1
        """
        rt = max(isqrt(k - 1), 1)
        return min(rt - 1 + (k - 1) // rt, rt + (k - 1) // (rt + 1))


def main():
    k = 11
    sol = Solution()
    print(sol.minOperations(k))


main()
