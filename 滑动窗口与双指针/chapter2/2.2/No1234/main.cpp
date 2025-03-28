#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int balancedString(string s) {
    int n = s.length();
    int m = n / 4, cnt['X']{};
    for (char &ch : s) {
      ++cnt[ch];
    }
    if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) {
      return 0;
    }
    int left = 0, ans = n;
    for (int i = 0; i < n; i++) {
      --cnt[s[i]];
      while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
        ans = min(ans, i - left + 1);
        ++cnt[s[left++]];
      }
    }

    return ans;
  }
};

signed main() {
  string s = "QQQW";
  Solution sol;
  cout << sol.balancedString(s) << endl;

  return 0;
}