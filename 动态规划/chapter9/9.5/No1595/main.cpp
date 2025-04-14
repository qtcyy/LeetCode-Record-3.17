#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int connectTwoGroups(vector<vector<int>> &cost) {
    int m = cost.size(), n = cost[0].size();
    vector<vector<int>> f(m + 1, vector<int>(1 << n));
    vector<int> mn(n, INT_MAX);
    for (int i = 0; i < n; i++) {
      for (auto &row : cost) {
        mn[i] = min(mn[i], row[i]);
      }
    }
    for (int i = 0; i < 1 << n; i++) {
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) {
          f[0][i] += mn[j];
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int s = 0; s < 1 << n; s++) {
        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
          res = min(res, f[i][s & ~(1 << j)] + cost[i][j]);
        }
        f[i + 1][s] = res;
      }
    }
    return f.back().back();
  }
};

signed main() {
  vector<vector<int>> cost = {
      {2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}};
  Solution sol;
  cout << sol.connectTwoGroups(cost) << endl;

  return 0;
}