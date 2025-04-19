/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 0; i < n; i++)
      pre[i + 1] = pre[i] + nums[i];
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = suf[i + 1] + nums[i];
    }
    for (int i = 0; i < n; i++) {
      if (pre[i] == suf[i + 1]) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end
