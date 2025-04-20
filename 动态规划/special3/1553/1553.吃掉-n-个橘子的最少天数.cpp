/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minDays(int n) {
    unordered_map<int, int> dis;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, n);
    while (true) {
      auto [pre, u] = pq.top();
      pq.pop();
      if (u <= 1) {
        return pre + u;
      }
      if (pre > dis[u])
        continue;
      for (int d = 2; d <= 3; d++) {
        int v = u / d;
        int s = pre + u % d + 1;
        if (!dis.contains(v) || dis[v] > s) {
          dis[v] = s;
          pq.emplace(s, v);
        }
      }
    }
    return 0;
  }
};
// @lc code=end
