#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minimumMoves(string s) {
    int n = s.length(), ans = 0;
    for (int i = 0; i < n - 2; i++) {
      if (s[i] == 'X') {
        ++ans;
        s[i] = s[i + 1] = s[i + 2] = 'O';
      }
    }
    if (s[n - 1] == 'X' || s[n - 2] == 'X') {
      ++ans;
    }
    return ans;
  }
};

signed main() {
  string s = "XXOX";
  Solution sol;
  cout << sol.minimumMoves(s) << endl;

  return 0;
}