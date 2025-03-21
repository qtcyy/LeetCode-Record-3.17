#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int n = s.length();
    vector<vector<int>> preRecorder(n, vector<int>(26)),
        sufRecorder(n, vector<int>(26));
    preRecorder[0][s[0] - 97] = 1;
    for (int i = 1; i < n; i++) {
      preRecorder[i] = preRecorder[i - 1];
      preRecorder[i][s[i] - 97]++;
    }
    sufRecorder[n - 1][s[n - 1] - 97] = 1;
    for (int i = n - 2; i >= 0; i--) {
      sufRecorder[i] = sufRecorder[i + 1];
      sufRecorder[i][s[i] - 97]++;
    }
    unordered_set<string> recorder;
    for (int i = 1; i < n - 1; i++) {
      for (int ch = 0; ch <= 25; ch++) {
        string temp = "";
        if (preRecorder[i - 1][ch] && sufRecorder[i + 1][ch]) {
          temp += ch;
          temp += s[i];
          temp += ch;
          recorder.insert(temp);
        }
      }
    }
    return recorder.size();
  }
};

signed main() {
  string s = "aabca";
  Solution sol = Solution();
  cout << sol.countPalindromicSubsequence(s) << endl;

  return 0;
}