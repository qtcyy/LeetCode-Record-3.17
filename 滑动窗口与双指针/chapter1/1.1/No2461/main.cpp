#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    unordered_map<int, int> cnt;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
      if (i < k) {
        ++cnt[nums[i]];
      } else {
        if (cnt.size() == k) {
          ans = max(ans, pre[i] - pre[i - k]);
        }
        if (i == n) {
          break;
        }
        if (!--cnt[nums[i - k]]) {
          cnt.erase(nums[i - k]);
        }
        ++cnt[nums[i]];
      }
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
  int k = 3;
  Solution sol;
  cout << sol.maximumSubarraySum(nums, k) << endl;

  return 0;
}