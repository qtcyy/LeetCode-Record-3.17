#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int partitionString(string s) {
    int ans = 1;
    bool cnt[26]{};
    for (auto &ch : s) {
      if (cnt[ch - 'a']) {
        memset(cnt, false, sizeof(cnt));
        ++ans;
      }
      cnt[ch - 'a'] = 1;
    }
    return ans;
  }
};

signed main() {
  string s = "abacaba";
  Solution sol;
  cout << sol.partitionString(s) << endl;

  return 0;
}