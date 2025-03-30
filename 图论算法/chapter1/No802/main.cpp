#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> vis(n);
    function<bool(int)> safe = [&](int u) -> bool {
      if (vis[u] > 0) {
        return vis[u] == 2;
      }
      vis[u] = 1;
      for (auto &v : graph[u]) {
        if (!safe(v)) {
          return false;
        }
      }
      vis[u] = 2;
      return true;
    };
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (safe(i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  Solution sol;
  vector<int> ans = sol.eventualSafeNodes(graph);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}