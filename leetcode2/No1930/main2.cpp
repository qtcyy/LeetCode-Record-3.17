#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int n = s.length();
    vector<unordered_set<char>> preRecorder(n), sufRecorder(n);
    preRecorder[0].insert(s[0]);
    for (int i = 1; i < n; i++) {
      preRecorder[i] = preRecorder[i - 1];
      preRecorder[i].insert(s[i]);
    }
    sufRecorder[n - 1].insert(s[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      sufRecorder[i] = sufRecorder[i + 1];
      sufRecorder[i].insert(s[i]);
    }
    unordered_set<string> recorder;
    for (int i = 1; i < n - 1; i++) {
      for (char ch = 'a'; ch <= 'z'; ch++) {
        string temp = "";
        if (preRecorder[i - 1].contains(ch) &&
            sufRecorder[i + 1].contains(ch)) {
          temp += ch;
          temp += s[i];
          temp += ch;
          recorder.insert(temp);
        }
      }
    }
    for (string st : recorder) {
      cout << st << ' ';
    }
    cout << endl;
    return recorder.size();
  }
};

signed main() {
  string s = "tlpjzdmtwderpkpmgoyrcxttiheassztncqvnfjeyxxp";
  Solution sol = Solution();

  cout << sol.countPalindromicSubsequence(s) << endl;

  return 0;
}