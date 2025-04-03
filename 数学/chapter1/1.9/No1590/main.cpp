#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    int k = pre.back() % p;
    if (k == 0) {
      return 0;
    }
    int ans = n + 1;
    unordered_map<int, int> cnt;
    cnt[0] = -1;
    for (int i = 0; i <= n; i++) {
      pre[i] %= p;
      int target = (pre[i] - k + p) % p;
      if (cnt.contains(target)) {
        ans = min(ans, i - cnt[target]);
      }
      cnt[pre[i]] = i;
    }
    if (ans == n + 1) {
      return -1;
    }

    return ans;
  }
};

class Solution2 {
public:
  int minSubarray(vector<int> &nums, int p) {
    int n = nums.size();
    int k = 0;
    for (int num : nums) {
      k = (k + num) % p;
    }
    if (k == 0)
      return 0;

    unordered_map<int, int> last_idx;
    last_idx[0] = -1; // 初始空前缀

    int curr_sum = 0;
    int ans = n;

    for (int i = 0; i < n; i++) {
      curr_sum = (curr_sum + nums[i]) % p;

      // 要找的前缀和余数：(curr_sum - k + p) % p
      int target = (curr_sum - k + p) % p;

      if (last_idx.count(target)) {
        ans = min(ans, i - last_idx[target]);
      }

      last_idx[curr_sum] = i;
    }

    return ans < n ? ans : -1;
  }
};

signed main() {
  vector<int> nums = {6, 3, 5, 2};
  int p = 9;
  Solution sol;
  cout << sol.minSubarray(nums, p) << endl;

  return 0;
}