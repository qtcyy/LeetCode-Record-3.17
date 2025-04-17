#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    vector<vector<int>> g(n);
    for (auto &p : edges) {
      --p[0];
      --p[1];
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    --target;
    double ans = -1;
    function<void(int, int, int, double)> dfs = [&](int u, int fa, int deep,
                                                    double p) {
      if (u == target && (t == deep || g[u].size() == 1)) {
        ans = p;
        return;
      }
      if (u == target || t == deep) {
        return;
      }
      double nxt = p / (u == 0 ? g[u].size() : (g[u].size() - 1));
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        dfs(v, u, deep + 1, nxt);
        if (ans != -1)
          break;
      }
    };
    dfs(0, -1, 0, 1);
    return ans;
  }
};

signed main() {
  int n = 7;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
  int t = 2, target = 4;
  Solution sol;
  cout << sol.frogPosition(n, edges, t, target) << endl;

  return 0;
}