class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        n = len(word)
        return max(word[i : i + n - numFriends + 1] for i in range(n))


def main():
    word = "dbca"
    numFriends = 2
    sol = Solution()
    print(sol.answerString(word, numFriends))


main()
