#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string reorganizeString(string s) {
    int n = s.length();
    int count[26]{}, m = 0;
    char mch;
    for (char ch : s) {
      if (++count[ch - 'a'] > m) {
        m = count[ch - 'a'];
        mch = ch;
      }
    }
    if (m > n - m + 1) {
      return "";
    }

    string ans(n, 0);
    int i = 0;
    for (; m--; i += 2) {
      ans[i] = mch;
    }
    count[mch - 'a'] = 0;

    for (int j = 0; j < 26; j++) {
      int cnt = count[j];
      while (cnt--) {
        if (i >= n) {
          i = 1;
        }
        ans[i] = 'a' + j;
        i += 2;
      }
    }
    return ans;
  }
};

signed main() {
  string s = "aab";
  Solution sol = Solution();
  cout << sol.reorganizeString(s) << endl;

  return 0;
}