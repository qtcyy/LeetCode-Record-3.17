/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        int sum = 0;
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++) {
            if (i >= 1) {
                pre[i] = pre[i - 1] + sum;
            }
            if (boxes[i] == '1') {
                ++sum;
            }
        }
        sum = 0;
        vector<int> suf(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i <= n - 2) {
                suf[i] = suf[i + 1] + sum;
            }
            if (boxes[i] == '1') {
                ++sum;
            }
        }
        for (int i = 0; i < n; i++)
            pre[i] += suf[i];
        return pre;
    }
};
// @lc code=end
