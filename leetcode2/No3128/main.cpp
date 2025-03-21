#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long numberOfRightTriangles(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> rowRecorder(n, 0), colRecorder(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          rowRecorder[i]++;
          colRecorder[j]++;
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          ans += (rowRecorder[i] - 1) * (colRecorder[j] - 1);
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> grid = {{0, 1, 0}, {0, 1, 1}, {0, 1, 0}};
  Solution sol = Solution();
  cout << sol.numberOfRightTriangles(grid) << endl;

  return 0;
}