#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int balancedStringSplit(string s) {
    int cntl = 0, cntr = 0, ans = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'R') {
        ++cntr;
      } else {
        ++cntl;
      }
      if (cntr == cntl) {
        cntr = 0;
        cntl = 0;
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  string s = "RLRRLLRLRL";
  Solution sol;
  cout << sol.balancedStringSplit(s) << endl;

  return 0;
}