#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestMagicSquare(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> row_sum(n, vector<int>(m + 1, 0)),
        col_sum(m, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        row_sum[i][j + 1] = row_sum[i][j] + grid[i][j];
        col_sum[j][i + 1] = col_sum[j][i] + grid[i][j];
      }
    }

    auto check = [&](int i, int j, int len) {
      int row_val = row_sum[i][j + len + 1] - row_sum[i][j];
      int col_val = col_sum[j][i + len + 1] - col_sum[j][i];
      if (row_val != col_val) {
        return false;
      }
      for (int x = i + 1; x <= i + len; ++x) {
        int val = row_sum[x][j + len + 1] - row_sum[x][j];
        if (val != row_val) {
          return false;
        }
      }
      for (int y = j + 1; y <= j + len; ++y) {
        int val = col_sum[y][i + len + 1] - col_sum[y][i];
        if (val != col_val) {
          return false;
        }
      }
      int tt = 0, tt2 = 0;
      for (int x = 0; x <= len; ++x) {
        tt += grid[x + i][x + j];
        tt2 += grid[x + i][len - x + j];
      }
      if (tt != row_val || tt2 != row_val) {
        return false;
      }

      return true;
    };
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < m - 1; ++j) {
        int max_len = min(n - 1 - i, m - 1 - j);
        for (int len = 1; len <= max_len; ++len) {
          if (check(i, j, len)) {
            ans = max(ans, len);
          }
        }
      }
    }
    return ans + 1;
  }
};

signed main() {
  vector<vector<int>> grid = {
      {7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};
  Solution sol = Solution();
  cout << sol.largestMagicSquare(grid) << endl;

  return 0;
}