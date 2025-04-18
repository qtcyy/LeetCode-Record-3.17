/*
 * @lc app=leetcode.cn id=582 lang=cpp
 *
 * [582] 杀掉进程
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  unordered_map<int, vector<int>> g;
  vector<int> ans;

  void dfs(int u) {
    ans.push_back(u);
    for (auto &v : g[u]) {
      dfs(v);
    }
  }

public:
  vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
    int n = pid.size(), root = 0;
    for (int i = 0; i < n; i++) {
      if (!ppid[i]) {
        root = i;
        continue;
      }
      g[ppid[i]].push_back(pid[i]);
    }
    dfs(kill);
    return ans;
  }
};
// @lc code=end
