#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> edge(n);
    for (auto &p : edges) {
      edge[p[0]].push_back(p[1]);
      edge[p[1]].push_back(p[0]);
    }
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      for (auto &v : edge[u]) {
        if (!vis[v]) {
          dfs(v);
        }
      }
    };
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        ++sum;
        dfs(i);
      }
    }
    return sum;
  }
};

signed main() {
  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
  Solution sol;
  cout << sol.countComponents(n, edges) << endl;

  return 0;
}