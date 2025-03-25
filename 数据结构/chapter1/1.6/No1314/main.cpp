#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        sum[i + 1][j + 1] =
            sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + mat[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int r1 = max(0, i - k), c1 = max(0, j - k);
        int r2 = min(n - 1, i + k), c2 = min(m - 1, j + k);
        ans[i][j] = sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] +
                    sum[r1][c1];
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int k = 1;
  Solution sol = Solution();
  vector<vector<int>> ans = sol.matrixBlockSum(mat, k);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}