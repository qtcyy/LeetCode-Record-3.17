/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    if (arr[start] == 0)
      return true;
    int n = arr.size();
    queue<int> q;
    q.push(start);
    vector<bool> vis(n, false);
    vis[start] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      int left = u - arr[u];
      if (left >= 0 && !vis[left]) {
        if (arr[left] == 0) {
          return true;
        }
        vis[left] = 1;
        q.push(left);
      }

      int right = u + arr[u];
      if (right < n && !vis[right]) {
        if (arr[right] == 0) {
          return true;
        }
        vis[right] = 1;
        q.push(right);
      }
    }
    return false;
  }
};
// @lc code=end
