#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    int sz = 0;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      ++sz;
      for (int v = 0; v < n; v++) {
        if (vis[v])
          continue;
        // dist<=r1+r2 bomb
        // dist>r1+r2 cant
        long long dist = 1ll * abs(bombs[u][0] - bombs[v][0]) *
                             abs(bombs[u][0] - bombs[v][0]) +
                         1ll * abs(bombs[u][1] - bombs[v][1]) *
                             abs(bombs[u][1] - bombs[v][1]);
        if (dist <= 1ll * bombs[u][2] * bombs[u][2]) {
          dfs(v);
        }
      }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      fill(vis.begin(), vis.end(), false);
      sz = 0;
      dfs(i);
      ans = max(ans, sz);
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> bombs = {
      {1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
  Solution sol;
  cout << sol.maximumDetonation(bombs) << endl;

  return 0;
}