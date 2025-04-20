/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    vector<int> pre(n + 1, 1), suf(n + 1, 1);
    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[i - 1]) {
        pre[i] = pre[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > arr[i + 1]) {
        suf[i] = suf[i + 1] + 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (pre[i] != 1 && suf[i] != 1)
        ans = max(ans, pre[i] + suf[i] - 1);
    }
    return ans < 3 ? 0 : ans;
  }
};
// @lc code=end
