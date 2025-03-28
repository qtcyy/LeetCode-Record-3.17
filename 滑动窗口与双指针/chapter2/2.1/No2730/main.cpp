#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int longestSemiRepetitiveSubstring(string s) {
    int n = s.length();
    int left = 0, ans = 1, cnt = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1]) {
        ++cnt;
      }
      if (cnt > 1) {
        ++left;
        while (s[left] != s[left - 1])
          ++left;
        cnt = 1;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  string s = "52233";
  Solution sol;
  cout << sol.longestSemiRepetitiveSubstring(s) << endl;

  return 0;
}