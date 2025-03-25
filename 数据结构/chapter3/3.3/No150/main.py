from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st: List[int] = []
        operations = set(["+", "-", "*", "/"])

        for item in tokens:
            if item[-1] in operations:
                op = item[-1]
                val = 0
                if op == "+":
                    val = st[-1] + st[-2]
                elif op == "-":
                    val = st[-2] - st[-1]
                elif op == "*":
                    val = st[-2] * st[-1]
                else:
                    val = int(st[-2] / st[-1])

                st.pop()
                st.pop()
                st.append(val)
            else:
                st.append(int(item))

        return st[-1]


def main():
    tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
    sol = Solution()
    print(sol.evalRPN(tokens))


main()
