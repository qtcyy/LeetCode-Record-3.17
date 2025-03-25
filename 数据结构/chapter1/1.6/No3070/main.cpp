#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i + 1][j + 1] =
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int val = sum[i + 1][j + 1] - sum[0][j + 1] - sum[i + 1][0] + sum[0][0];
        if (val <= k) {
          ++ans;
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> grid = {{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
  int k = 20;
  Solution sol = Solution();
  cout << sol.countSubmatrices(grid, k) << endl;

  return 0;
}