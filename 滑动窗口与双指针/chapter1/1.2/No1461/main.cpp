#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int n = s.length();
    int mx = (int)pow(2, k);
    vector<bool> vis(mx, false);
    for (int i = 0; i < n - k + 1; i++) {
      int val = 0;
      for (int j = i; j < i + k; j++) {
        val <<= 1;
        val |= (s[j] == '1');
      }
      vis[val] = 1;
    }
    for (int i = 0; i < mx; i++) {
      if (!vis[i])
        return false;
    }
    return true;
  }
};

signed main() {
  string s = "00110";
  int k = 2;
  Solution sol;
  cout << (sol.hasAllCodes(s, k) ? "true" : "false") << endl;

  return 0;
}