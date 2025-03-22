#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int mx = 0, n = heights.size(), m = heights[0].size();
    for (auto &row : heights) {
      mx = max(mx, ranges::max(row));
    }
    auto check = [&](const int &mid) {
      queue<pair<int, int>> que;
      que.push(make_pair(0, 0));
      vector<vector<bool>> vis(n, vector<bool>(m, false));
      while (!que.empty()) {
        auto [x, y] = que.front();
        if (x == n - 1 && y == m - 1) {
          return true;
        }
        que.pop();
        if (vis[x][y])
          continue;
        vis[x][y] = 1;
        for (int k = 0; k <= 3; k++) {
          int tx = x + dx[k], ty = y + dy[k];
          if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty]) {
            continue;
          }
          if (abs(heights[tx][ty] - heights[x][y]) <= mid) {
            que.push(make_pair(tx, ty));
          }
        }
      }
      return false;
    };
    int l = -1, r = mx + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  }
};

signed main() {
  vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  Solution sol = Solution();
  cout << sol.minimumEffortPath(heights) << endl;

  return 0;
}