#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
    int n = graph.size();
    vector<bool> vis(n);
    unordered_set<int> base(initial.begin(), initial.end());
    int node_id = -1, sz = 0;
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      ++sz;
      for (int v = 0; v < n; v++) {
        if (!graph[u][v]) {
          continue;
        }
        if (base.contains(v)) {
          if (node_id != -2 && node_id != v) {
            node_id = node_id == -1 ? v : -2;
          }
        } else if (!vis[v]) {
          dfs(v);
        }
      }
    };
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      if (vis[i] || base.contains(i)) {
        continue;
      }
      node_id = -1;
      sz = 0;
      dfs(i);
      if (node_id > 0) {
        cnt[node_id] += sz;
      }
    }
    if (cnt.size() == 0) {
      return ranges::min(initial);
    }
    int mx = 0, ans = 0;
    for (auto &&[id, c] : cnt) {
      if (c > mx || (c == mx && id < ans)) {
        mx = c;
        ans = id;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> graph = {
      {1, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 1, 1}, {0, 0, 1, 1}};
  vector<int> initial = {0, 1};
  Solution sol;
  cout << sol.minMalwareSpread(graph, initial) << endl;

  return 0;
}