/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
  vector<vector<int>> g;
  vector<int> deep;

  void dfs(int u, int fa) {
    for (int &v : g[u]) {
      if (v == fa)
        continue;
      deep[v] = deep[u] + 1;
      dfs(v, u);
    }
  }

public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    g.resize(n);
    deep.resize(n);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    dfs(0, -1);
  }
};
// @lc code=end
