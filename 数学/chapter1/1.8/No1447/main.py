from typing import List
import math


class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        ans = []
        for i in range(2, n + 1):
            for j in range(1, i):
                if math.gcd(i, j) == 1:
                    ans.append(str(j) + "/" + str(i))
        return ans


def main():
    sol = Solution()
    print(sol.simplifiedFractions(4))


main()
