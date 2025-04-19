/*
 * @lc app=leetcode.cn id=3224 lang=cpp
 *
 * [3224] 使差值相等的最少数组改动次数
 */
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minChanges(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> cnt(k + 1), cnt2(k + 1);
    for (int i = 0; i < n / 2; i++) {
      int p = nums[i], q = nums[n - i - 1];
      if (p > q)
        swap(p, q);
      ++cnt[q - p];
      ++cnt2[max(q, k - p)];
    }
    int ans = n;
    int sum = 0;
    for (int i = 0; i <= k; i++) {
      ans = min(ans, n / 2 - cnt[i] + sum);
      sum += cnt2[i];
    }
    return ans;
  }
};
// @lc code=end
