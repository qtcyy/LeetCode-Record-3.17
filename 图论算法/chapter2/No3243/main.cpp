#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      g[i].push_back(i + 1);
    }
    vector<int> vis(n, -1);
    auto bfs = [&](int i) -> int {
      queue<pair<int, int>> q;
      q.push(make_pair(0, 0));
      while (!q.empty()) {
        auto [u, step] = q.front();
        q.pop();
        if (u == n - 1) {
          return step;
        }
        if (vis[u] == i) {
          continue;
        }
        vis[u] = i;
        for (auto &v : g[u]) {
          if (vis[v] == i)
            continue;
          q.push(make_pair(v, step + 1));
        }
      }
      return 0;
    };
    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      g[queries[i][0]].push_back(queries[i][1]);
      ans[i] = bfs(i);
    }
    return ans;
  }
};

signed main() {
  int n = 5;
  vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
  Solution sol;
  vector<int> ans = sol.shortestDistanceAfterQueries(n, queries);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}