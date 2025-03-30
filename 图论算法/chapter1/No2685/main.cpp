#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> edge(n);
    for (auto &p : edges) {
      edge[p[0]].push_back(p[1]);
      edge[p[1]].push_back(p[0]);
    }
    // 统计点/边
    int sum1 = 0, sum2 = 0;
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      ++sum1;
      sum2 += edge[u].size();
      for (auto &v : edge[u]) {
        if (vis[v])
          continue;
        dfs(v);
      }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        sum1 = sum2 = 0;
        dfs(i);
        ans += sum2 == sum1 * (sum1 - 1);
      }
    }
    return ans;
  }
};

signed main() {
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
  Solution sol;
  cout << sol.countCompleteComponents(n, edges) << endl;

  return 0;
}