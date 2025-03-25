#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0)),
        spray(n + 1, vector<int>(m + 1, 0));
    unordered_map<char, int> inter{{'X', 1}, {'Y', -1}, {'.', 0}};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i + 1][j + 1] =
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + inter[grid[i][j]];
        spray[i + 1][j + 1] = spray[i + 1][j] + spray[i][j + 1] - spray[i][j] +
                              (grid[i][j] == 'X');
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int val = sum[i + 1][j + 1];
        if (val == 0 && spray[i + 1][j + 1]) {
          ++ans;
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<char>> grid = {{'X', 'Y', '.'}, {'Y', '.', '.'}};
  Solution sol = Solution();
  cout << sol.numberOfSubmatrices(grid) << endl;

  return 0;
}