#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int n = s.length();
    vector<unordered_map<char, int>> preRecorder(n), sufRecorder(n);
    preRecorder[0][s[0]]++;
    for (int i = 1; i < n; i++) {
      preRecorder[i] = preRecorder[i - 1];
      preRecorder[i][s[i]]++;
    }
    sufRecorder[n - 1][s[n - 1]]++;
    for (int i = n - 2; i >= 0; i--) {
      sufRecorder[i] = sufRecorder[i + 1];
      sufRecorder[i][s[i]]++;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      for (char ch = 'a'; ch <= 'z'; ch++) {
        if (preRecorder[i - 1].contains(ch) &&
            sufRecorder[i + 1].contains(ch)) {
          ans += preRecorder[i - 1][ch] * sufRecorder[i + 1][ch];
        }
      }
    }
    return ans;
  }
};

signed main() {
  string s = "aabca";
  Solution sol = Solution();
  cout << sol.countPalindromicSubsequence(s) << endl;

  return 0;
}