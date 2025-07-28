/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
typedef long long ll;

class Solution {
  public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<ll> pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + chalk[i];
        if (pre[n] > k) {
            for (int i = 1; i <= n; i++) {
                if (pre[i] > k) {
                    return i - 1;
                }
            }
        } else {
            int base = k % pre[n];
            for (int i = 1; i <= n; i++) {
                if (pre[i] > base) {
                    return i - 1;
                }
            }
        }
        return 0;
    }
};
// @lc code=end
