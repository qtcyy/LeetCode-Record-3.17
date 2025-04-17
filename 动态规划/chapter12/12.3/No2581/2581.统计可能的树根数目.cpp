/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 *
 * [2581] 统计可能的树根数目
 */
#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
typedef long long ll;

class Solution {
public:
  int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses,
                int k) {
    int n = edges.size() + 1;
    vector<vector<int>> g(n);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    unordered_set<ll> s;
    for (auto &p : guesses) {
      s.insert((ll)p[0] << 32 | p[1]);
    }
    int cnt0 = 0;
    function<void(int, int)> dfs = [&](int u, int fa) {
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        cnt0 += s.count((ll)u << 32 | v);
        dfs(v, u);
      }
    };
    dfs(0, -1);
    int ans = 0;
    function<void(int, int, int)> dfs2 = [&](int u, int fa, int cnt) {
      ans += cnt >= k;
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        dfs2(v, u, cnt - s.count((ll)u << 32 | v) + s.count((ll)v << 32 | u));
      }
    };
    dfs2(0, -1, cnt0);
    return ans;
  }
};
// @lc code=end
