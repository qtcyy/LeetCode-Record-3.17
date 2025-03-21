#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArrayLen(vector<int> &nums, int k) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    vector<long long> pre_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre_sum[i] = pre_sum[i - 1] + nums[i];
    }
    unordered_map<long long, int> recorder = {{0, 0}};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      long long val = pre_sum[i] - k;
      if (recorder.contains(val)) {
        ans = max(ans, i - recorder[val]);
      }
      if (!recorder.contains(pre_sum[i])) {
        recorder[pre_sum[i]] = i;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, -1, 5, -2, 3};
  int k = 3;
  Solution sol = Solution();
  cout << sol.maxSubArrayLen(nums, k) << endl;

  return 0;
}