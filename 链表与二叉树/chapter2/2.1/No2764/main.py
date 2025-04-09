from typing import List


class Solution:
    def isPreorder(self, nodes: List[List[int]]) -> bool:
        stk = [-1]
        for node, fa in nodes:
            while stk and stk[-1] != fa:
                print(stk.pop())
            if not stk:
                return False
            stk.append(node)
        return True


def main():
    nodes = [[0, -1], [1, 0], [2, 0], [3, 2], [4, 2]]
    sol = Solution()
    print(sol.isPreorder(nodes))


main()
