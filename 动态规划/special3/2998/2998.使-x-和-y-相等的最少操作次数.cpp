/*
 * @lc app=leetcode.cn id=2998 lang=cpp
 *
 * [2998] 使 X 和 Y 相等的最少操作次数
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
const int N = 5e4 + 5;
class Solution {
public:
  int minimumOperationsToMakeEqual(int x, int y) {
    if (x == y) {
      return 0;
    }
    vector<int> dis(N, -1);
    dis[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      int next1 = u + 1;
      if (dis[next1] == -1) {
        dis[next1] = dis[u] + 1;
        q.push(next1);
        if (next1 == y) {
          return dis[next1];
        }
      }
      if (u < y)
        continue;
      int next2 = u - 1;

      if (u % 11 == 0) {
        int next3 = u / 11;
        if (dis[next3] == -1) {
          dis[next3] = dis[u] + 1;
          q.push(next3);
          if (next3 == y) {
            return dis[next3];
          }
        }
      }

      if (u % 5 == 0) {
        int next4 = u / 5;
        if (dis[next4] == -1) {
          dis[next4] = dis[u] + 1;
          q.push(next4);
          if (next4 == y) {
            return dis[next4];
          }
        }
      }

      if (dis[next2] == -1) {
        dis[next2] = dis[u] + 1;
        q.push(next2);
        if (next2 == y) {
          return dis[next2];
        }
      }
    }
    return -1;
  }
};
// @lc code=end
