#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> edge(n);
    for (auto &p : edges) {
      edge[p[0]].push_back(p[1]);
    }
    vector<int> vis(n, -1);
    vector<vector<int>> ans(n);
    int start;
    function<void(int)> dfs = [&](int u) {
      vis[u] = start;
      for (auto &v : edge[u]) {
        if (vis[v] != start) {
          ans[v].push_back(start);
          dfs(v);
        }
      }
    };
    for (start = 0; start < n; start++) {
      dfs(start);
    }
    return ans;
  }
};

signed main() {
  int n = 8;
  vector<vector<int>> edgeList = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7},
                                  {3, 5}, {3, 6}, {3, 7}, {4, 6}};
  Solution sol;
  vector<vector<int>> ans = sol.getAncestors(n, edgeList);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}