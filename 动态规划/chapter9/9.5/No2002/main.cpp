#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProduct(string s) {
    int n = s.length();
    vector<int> sum(1 << n);
    for (int i = 1; i < 1 << n; i++) {
      string cur;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) {
          cur.push_back(s[j]);
        }
      }
      int len = cur.length();
      bool flag = true;
      for (int p = 0; p * 2 < len; p++) {
        if (cur[p] != cur[len - p - 1]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        sum[i] = len;
      }
    }
    int ans = 0;
    for (int i = 1; i < 1 << n; i++) {
      if (!sum[i])
        continue;
      for (int j = 1; j < 1 << n; j++) {
        if (!sum[j] || i & j)
          continue;
        ans = max(ans, sum[i] * sum[j]);
      }
    }
    return ans;
  }
};

signed main() {
  string s = "accbcaxxcxx";
  Solution sol;
  cout << sol.maxProduct(s) << endl;

  return 0;
}