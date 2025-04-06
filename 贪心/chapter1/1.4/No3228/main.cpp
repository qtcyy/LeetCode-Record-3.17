#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int maxOperations(string s) {
    int cnt = 0, ans = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        ++cnt;
      } else if (i && s[i - 1] == '1') {
        ans += cnt;
      }
    }
    return ans;
  }
};

signed main() {
  string s = "1001101";
  Solution sol;
  cout << sol.maxOperations(s) << endl;

  return 0;
}