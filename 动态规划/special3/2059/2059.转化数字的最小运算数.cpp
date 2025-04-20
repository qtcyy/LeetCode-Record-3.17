/*
 * @lc app=leetcode.cn id=2059 lang=cpp
 *
 * [2059] 转化数字的最小运算数
 */
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minimumOperations(vector<int> &nums, int start, int goal) {
    int n = nums.size();
    vector<int> dis(5005, -1);
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u < 0 || u > 1000)
        continue;
      for (int &v : nums) {
        int nexts[3] = {u + v, u - v, u ^ v};
        for (int next : nexts) {
          if (next == goal)
            return dis[u] + 1;
          if (next >= 0 && next <= 1000 && dis[next] == -1) {
            dis[next] = dis[u] + 1;
            q.push(next);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
