#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumMoves(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> from, to;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          for (int k = 1; k < grid[i][j]; k++) {
            from.emplace_back(i, j);
          }
        } else {
          to.emplace_back(i, j);
        }
      }
    int ans = INT_MAX;
    do {
      int tot = 0;
      for (int i = 0; i < from.size(); i++) {
        tot += abs(from[i].first - to[i].first) +
               abs(from[i].second - to[i].second);
      }
      ans = min(ans, tot);
    } while (next_permutation(from.begin(), from.end()));

    return ans;
  }
};

signed main() {
  vector<vector<int>> grid = {{1, 3, 0}, {1, 0, 0}, {1, 0, 3}};
  Solution sol;
  cout << sol.minimumMoves(grid) << endl;

  return 0;
}