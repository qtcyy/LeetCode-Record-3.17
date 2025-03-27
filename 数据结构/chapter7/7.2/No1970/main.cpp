#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      f[x] = y;
    }
  }

public:
  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    int n = row * col;
    f.resize(n + 2);
    iota(f.begin(), f.end(), 0);
    vector<vector<bool>> vis(row, vector<bool>(col, false));
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      int x = cells[i][0] - 1, y = cells[i][1] - 1;
      vis[x][y] = 1;
      int id = x * col + y;
      if (x - 1 >= 0 && vis[x - 1][y]) {
        merge(id - col, id);
      }
      if (x + 1 < row && vis[x + 1][y]) {
        merge(id + col, id);
      }
      if (y - 1 >= 0 && vis[x][y - 1]) {
        merge(id, id - 1);
      }
      if (y + 1 < col && vis[x][y + 1]) {
        merge(id, id + 1);
      }
      if (x == 0) {
        merge(id, n);
      }
      if (x == row - 1) {
        merge(id, n + 1);
      }
      if (find(n) == find(n + 1)) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};

signed main() {
  int row = 3, col = 3;
  vector<vector<int>> cells = {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1},
                               {1, 3}, {2, 3}, {3, 2}, {3, 1}};
  Solution sol;
  cout << sol.latestDayToCross(row, col, cells) << endl;

  return 0;
}