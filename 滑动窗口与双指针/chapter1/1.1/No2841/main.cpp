#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxSum(vector<int> &nums, int m, int k) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    unordered_map<int, int> mp;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
      if (i < k) {
        ++mp[nums[i]];
      } else {
        if (mp.size() >= m) {
          ans = max(ans, pre[i] - pre[i - k]);
        }
        if (i == n)
          continue;

        ++mp[nums[i]];
        if (!--mp[nums[i - k]]) {
          mp.erase(nums[i - k]);
        }
      }
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 6, 7, 3, 1, 7};
  int m = 3, k = 4;
  Solution sol;
  cout << sol.maxSum(nums, m, k) << endl;

  return 0;
}