#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    vector<long long> pre_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre_sum[i] = pre_sum[i - 1] + nums[i];
    }
    map<int, vector<int>> cnt;
    cnt[nums[1]].push_back(1);
    const long long INF = 0x1f1f1f1f1f1f3f;
    long long ans = -INF;
    for (int i = 2; i <= n; i++) {
      if (cnt.contains(nums[i] + k)) {
        vector<int> idx = cnt[nums[i] + k];
        for (auto &j : idx) {
          ans = max(ans, pre_sum[i] - pre_sum[j - 1]);
        }
      }
      if (cnt.contains(nums[i] - k)) {
        vector<int> idx = cnt[nums[i] - k];
        for (auto &j : idx) {
          ans = max(ans, pre_sum[i] - pre_sum[j - 1]);
        }
      }
      cnt[nums[i]].push_back(i);
    }
    return ans == -INF ? 0 : ans;
  }
};

signed main() {
  vector<int> nums = {1, 3, 8, 9, 5};
  int k = 4;
  Solution sol = Solution();
  cout << sol.maximumSubarraySum(nums, k) << endl;

  return 0;
}