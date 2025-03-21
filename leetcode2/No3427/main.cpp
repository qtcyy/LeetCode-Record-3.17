#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums) {
    nums.insert(nums.begin(), 0);
    int n = nums.size();
    vector<int> pre_sum(n, 0);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      pre_sum[i] = pre_sum[i - 1] + nums[i];
      int start = max(0, i - nums[i]);
      if (start == 0)
        start = 1;
      cout << start << ' ';
      ans += pre_sum[i] - pre_sum[start - 1];
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 3, 1};
  Solution sol = Solution();

  cout << sol.subarraySum(nums) << endl;

  return 0;
}