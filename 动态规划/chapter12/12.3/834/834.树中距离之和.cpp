/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    vector<int> deep(n), f(n), sz(n);
    function<void(int, int)> dfs1 = [&](int u, int fa) {
      sz[u] = 1;
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        deep[v] = deep[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
      }
    };
    dfs1(0, -1);
    for (int i = 0; i < n; i++)
      f[0] += deep[i];
    function<void(int, int)> dfs2 = [&](int u, int fa) {
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        f[v] = f[u] - 2 * sz[v] + n;
        dfs2(v, u);
      }
    };
    dfs2(0, -1);
    return f;
  }
};
// @lc code=end
