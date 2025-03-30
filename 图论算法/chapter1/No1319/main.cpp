#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    int m = connections.size();
    if (m < n - 1) {
      return -1;
    }
    vector<vector<int>> edge(n);
    vector<bool> vis(n);
    for (auto &p : connections) {
      edge[p[0]].push_back(p[1]);
      edge[p[1]].push_back(p[0]);
    }
    function<void(int)> dfs = [&](int u) -> void {
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
    return sum - 1;
  }
};

signed main() {
  int n = 6;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

  Solution sol;
  cout << sol.makeConnected(n, connections) << endl;

  return 0;
}