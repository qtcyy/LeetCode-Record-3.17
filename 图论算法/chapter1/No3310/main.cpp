#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
    vector<vector<int>> edge(n);
    for (auto &p : invocations) {
      edge[p[0]].push_back(p[1]);
    }
    vector<int> vis(n);
    function<void(int, int)> dfs = [&](int u, int &&signal) {
      vis[u] = signal;
      for (auto &v : edge[u]) {
        if (vis[v] == signal)
          continue;
        dfs(v, signal);
      }
    };
    dfs(k, 2);
    for (auto &p : invocations) {
      if (!vis[p[0]] && vis[p[1]]) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        return ans;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(i, 1);
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (vis[i] == 1) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

signed main() {
  int n = 5, k = 0;
  vector<vector<int>> invocations = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
  Solution sol;
  vector<int> ans = sol.remainingMethods(n, k, invocations);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}