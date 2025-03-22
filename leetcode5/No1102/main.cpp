#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
  int maximumMinimumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    auto check = [&](const int &mid) {
      if (grid[0][0] < mid) {
        return false;
      }
      queue<pair<int, int>> que;
      vector<vector<bool>> vis(n, vector<bool>(m, false));
      que.push(make_pair(0, 0));
      while (!que.empty()) {
        auto [x, y] = que.front();
        if (x == n - 1 && y == m - 1) {
          return true;
        }
        que.pop();
        if (vis[x][y])
          continue;
        vis[x][y] = true;
        for (int k = 0; k <= 3; k++) {
          int tx = x + dx[k], ty = y + dy[k];
          if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty]) {
            continue;
          }
          if (grid[tx][ty] >= mid) {
            que.push(make_pair(tx, ty));
          }
        }
      }
      return false;
    };
    int mn = INT_MAX, mx = 0;
    for (auto &row : grid) {
      auto [minn, maxn] = ranges::minmax(row);
      mn = min(mn, minn);
      mx = max(mx, maxn);
    }
    int l = mn - 1, r = mx + 1;
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

signed main() {
  vector<vector<int>> grid = {{3, 4, 6, 3, 4}, {0, 2, 1, 1, 7},
                              {8, 8, 3, 2, 7}, {3, 2, 4, 9, 8},
                              {4, 1, 2, 0, 0}, {4, 6, 5, 4, 3}};
  Solution sol = Solution();
  cout << sol.maximumMinimumPath(grid) << endl;

  return 0;
}