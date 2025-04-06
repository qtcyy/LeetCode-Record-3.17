#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] <= grid[i - 1][j]) {
          ans += grid[i - 1][j] - grid[i][j] + 1;
          grid[i][j] = grid[i - 1][j] + 1;
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> grid = {{3, 2}, {1, 3}, {3, 4}, {0, 1}};
  Solution sol;
  cout << sol.minimumOperations(grid) << endl;

  return 0;
}