#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    // zero[i]-zero[j-1]==one[i]-one[j-1]
    // => zero[i]-one[i]==zero[j-1]-one[j-1]
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    vector<int> pre_zero(n, 0), pre_one(n, 0), pre_diff(n, 0);
    for (int i = 1; i <= n; ++i) {
      pre_zero[i] = pre_zero[i - 1] + (nums[i] == 0);
      pre_one[i] = pre_one[i - 1] + (nums[i]);
      pre_diff[i] = pre_zero[i] - pre_one[i];
    }
    unordered_map<int, int> cnt{{0, 0}, {pre_diff[1], 1}};
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      if (cnt.contains(pre_diff[i])) {
        ans = max(ans, i - cnt[pre_diff[i]]);
        cnt[pre_diff[i]] = min(cnt[pre_diff[i]], i);
      } else {
        cnt[pre_diff[i]] = i;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {0, 1};
  Solution sol = Solution();
  cout << sol.findMaxLength(nums) << endl;

  return 0;
}