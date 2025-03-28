#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int maximumLengthSubstring(string s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      unordered_map<char, int> cnt;
      int j = i;
      for (j = i; j < n; j++) {
        if (++cnt[s[j]] == 3) {
          ans = max(ans, j - i);
          --j;
          break;
        }
      }
      if (j == n) {
        ans = max(ans, n - i);
      }
    }

    return ans;
  }
};

signed main() {
  string s = "bcbbbcba";
  Solution sol;
  cout << sol.maximumLengthSubstring(s) << endl;

  return 0;
}