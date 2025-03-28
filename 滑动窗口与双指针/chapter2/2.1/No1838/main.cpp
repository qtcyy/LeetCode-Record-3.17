#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    int n = nums.size();
    ranges::sort(nums);
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      while (1ll * (i - left + 1) * nums[i] - pre[i + 1] + pre[left] > k) {
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 4, 8, 13};
  int k = 5;
  Solution sol;
  cout << sol.maxFrequency(nums, k) << endl;

  return 0;
}