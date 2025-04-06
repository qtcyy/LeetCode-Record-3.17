#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    vector<vector<int>> g(n);
    vector<int> degree(n);
    for (auto &p : richer) {
      g[p[0]].push_back(p[1]);
      ++degree[p[1]];
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (!degree[i]) {
        q.push(i);
      }
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &v : g[u]) {
        if (quiet[ans[u]] < quiet[ans[v]]) {
          ans[v] = ans[u];
        }
        if (!--degree[v]) {
          q.push(v);
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7},
                                {4, 3}, {5, 3}, {6, 3}};
  vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};
  Solution sol;
  vector<int> ans = sol.loudAndRich(richer, quiet);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}