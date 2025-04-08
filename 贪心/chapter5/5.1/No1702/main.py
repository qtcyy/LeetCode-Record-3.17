from collections import Counter


class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        i = binary.find("0")
        if i < 0:
            return binary
        cnt1 = binary.count("1", i)
        return "1" * (len(binary) - 1 - cnt1) + "0" + "1" * cnt1


class Solution2:
    def maximumBinaryString(self, binary: str) -> str:
        i = binary.find("0")
        if i < 0:
            return binary
        s = binary[i:]
        cnt = Counter(s)
        ans = binary[:i]
        ans += "1" * (cnt["0"] - 1)
        ans += "0"
        ans += "1" * (cnt["1"])

        return ans


def main():
    binary = "1100"
    sol = Solution2()
    print(sol.maximumBinaryString(binary))


main()
