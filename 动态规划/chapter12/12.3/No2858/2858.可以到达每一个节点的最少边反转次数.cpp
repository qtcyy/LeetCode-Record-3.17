/*
 * @lc app=leetcode.cn id=2858 lang=cpp
 *
 * [2858] 可以到达每一个节点的最少边反转次数
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start

typedef long long ll;

class Solution {
  vector<vector<int>> g;
  unordered_set<ll> s;
  vector<int> ans;
  int cnt0 = 0;

  void dfs(int u, int fa) {
    for (auto &v : g[u]) {
      if (v == fa)
        continue;
      cnt0 += s.count((ll)v << 32 | u);
      dfs(v, u);
    }
  }

  void dfs2(int u, int fa, int cnt) {
    ans[u] = cnt;
    for (auto &v : g[u]) {
      if (v == fa)
        continue;
      dfs2(v, u, cnt - s.count((ll)v << 32 | u) + s.count((ll)u << 32 | v));
    }
  }

public:
  vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
    g.resize(n);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
      s.insert((ll)p[0] << 32 | p[1]);
    }
    dfs(0, -1);
    ans.resize(n);
    dfs2(0, -1, cnt0);
    return ans;
  }
};
// @lc code=end
