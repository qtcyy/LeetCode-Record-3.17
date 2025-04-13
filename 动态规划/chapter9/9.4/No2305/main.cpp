#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int distributeCookies(vector<int> &cookies, int k) {
    int n = cookies.size();
    vector<int> sum(1 << n);
    for (int i = 1; i < 1 << n; i++) {
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          sum[i] += cookies[j];
        }
      }
    }
    vector<vector<int>> f(k, vector<int>(1 << n));
    f[0] = sum;
    for (int i = 1; i < k; i++) {
      for (int s = 1; s < 1 << n; s++) {
        f[i][s] = 1e9;
        for (int j = s; j; j = s & (j - 1)) {
          f[i][s] = min(f[i][s], max(f[i - 1][s ^ j], sum[j]));
        }
      }
    }
    return f.back().back();
  }
};

signed main() {
  vector<int> cookies = {8, 15, 10, 20, 8};
  int k = 2;
  Solution sol;
  cout << sol.distributeCookies(cookies, k) << endl;

  return 0;
}