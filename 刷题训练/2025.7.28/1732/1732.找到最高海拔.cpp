/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int sum = 0, ans = 0;
        for (int& x : gain) {
            sum += x;
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end
