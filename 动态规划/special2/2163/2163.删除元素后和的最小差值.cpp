/*
 * @lc app=leetcode.cn id=2163 lang=cpp
 *
 * [2163] 删除元素后和的最小差值
 */
#include <climits>
#include <functional>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
typedef long long ll;
class Solution {
public:
  long long minimumDifference(vector<int> &nums) {
    int n = nums.size() / 3;
    ll preTotal = accumulate(nums.begin(), nums.begin() + n, 0ll);
    priority_queue<ll> pq(nums.begin(), nums.begin() + n);
    vector<ll> pre(n + 1);
    pre[0] = preTotal;
    for (int i = n; i < n * 2; i++) {
      pq.push(nums[i]);
      int mx = pq.top();
      pq.pop();
      preTotal += nums[i] - mx;
      pre[i - n + 1] = preTotal;
    }

    ll sufTotal = accumulate(nums.begin() + 2 * n, nums.end(), 0ll);
    priority_queue<ll, vector<ll>, greater<>> sufPq(nums.begin() + 2 * n,
                                                    nums.end());
    vector<ll> suf(n + 1);
    suf[n] = sufTotal;
    for (int i = n * 2 - 1; i >= n; i--) {
      sufPq.push(nums[i]);
      int mn = sufPq.top();
      sufPq.pop();
      sufTotal += nums[i] - mn;
      suf[i - n + 1] = sufTotal;
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i <= n; i++) {
      ans = min(ans, pre[i] - suf[i]);
    }
    return ans;
  }
};
// @lc code=end
