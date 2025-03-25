#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0));
    for (auto &q : queries) {
      int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
      diff[r1 + 1][c1 + 1]++;
      diff[r1 + 1][c2 + 2]--;
      diff[r2 + 2][c1 + 1]--;
      diff[r2 + 2][c2 + 2]++;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
      }
    }
    diff.pop_back();
    diff.erase(diff.begin());
    for (auto &row : diff) {
      row.pop_back();
      row.erase(row.begin());
    }
    return diff;
  }
};

signed main() {
  int n = 3;
  vector<vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};
  Solution sol = Solution();
  vector<vector<int>> ans = sol.rangeAddQueries(n, queries);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}