#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    vector<vector<int>> edge(n);
    for (auto &p : edges) {
      edge[p[0]].push_back(p[1]);
      edge[p[1]].push_back(p[0]);
    }
    vector<bool> vis(n, false);
    function<int(int)> dfs = [&](int u) -> int {
      vis[u] = 1;
      int sz = 1;
      for (auto &v : edge[u]) {
        if (!vis[v]) {
          sz += dfs(v);
        }
      }
      return sz;
    };

    long long ans = 0, tot = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        long long sz = dfs(i);
        ans += tot * sz;
        tot += sz;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
  int n = 7;
  Solution sol;
  cout << sol.countPairs(n, edges) << endl;

  return 0;
}