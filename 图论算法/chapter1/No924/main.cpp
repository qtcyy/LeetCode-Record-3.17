#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
    int signal = -1, n = graph.size();
    vector<bool> vis(n);
    unordered_set<int> st;
    for (auto &p : initial) {
      st.insert(p);
    }

    int ans = -1, sz = 0;
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      ++sz;
      if (signal != -2 && st.contains(u)) {
        signal = signal == -1 ? u : -2;
      }
      for (int i = 0; i < n; i++) {
        if (graph[u][i] && !vis[i]) {
          dfs(i);
        }
      }
    };
    int mx = 0;
    for (auto &p : initial) {
      if (vis[p])
        continue;
      signal = -1;
      sz = 0;
      dfs(p);
      if (signal > 0 && (sz > mx || sz == mx && signal < ans)) {
        ans = signal;
        mx = sz;
      }
    }
    return ans < 0 ? ranges::min(initial) : ans;
  }
};

signed main() {
  vector<vector<int>> graph = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  vector<int> initial = {0, 1};
  Solution sol;
  cout << sol.minMalwareSpread(graph, initial) << endl;

  return 0;
}