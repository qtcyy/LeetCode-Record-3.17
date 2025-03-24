from typing import List


class Solution:
    def calPoints(self, operations: List[str]) -> int:
        st = []
        for item in operations:
            if item.isalpha() or item == "+":
                if item == "C":
                    st.pop()
                elif item == "D":
                    st.append(st[-1] * 2)
                else:
                    st.append(st[-1] + st[-2])
            else:
                val = int(item)
                st.append(val)
        return sum(st)


def main():
    ops = ["5", "2", "C", "D", "+"]
    sol = Solution()
    print(sol.calPoints(ops))


if __name__ == "__main__":
    main()
