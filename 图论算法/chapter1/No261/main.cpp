#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    if (edges.size() >= n) {
      return false;
    }
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
    if (sum > 1 || edge.size() != n - 1) {
      return false;
    }
    return true;
  }
};

signed main() {
  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  Solution sol;
  cout << sol.validTree(n, edges) << endl;

  return 0;
}