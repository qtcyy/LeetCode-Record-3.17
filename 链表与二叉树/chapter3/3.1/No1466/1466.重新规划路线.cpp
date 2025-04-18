/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
typedef long long ll;
class Solution {
  vector<vector<int>> g;
  unordered_set<ll> s;
  int ans = 0;

  void dfs(int u, int fa) {
    for (auto &v : g[u]) {
      if (v == fa)
        continue;
      ans += s.count((ll)u << 32 | v);
      dfs(v, u);
    }
  }

public:
  int minReorder(int n, vector<vector<int>> &connections) {
    g.resize(n);
    for (auto &p : connections) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
      s.insert((ll)p[0] << 32 | p[1]);
    }
    dfs(0, -1);
    return ans;
  }
};
// @lc code=end
