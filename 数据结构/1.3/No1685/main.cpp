#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre_sum[i + 1] = pre_sum[i] + nums[i];
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
      res[i] = i * nums[i] - pre_sum[i] + (pre_sum[n] - pre_sum[i + 1]) -
               (n - i - 1) * nums[i];
    }
    return res;
  }
};

signed main() {
  vector<int> nums = {1, 4, 6, 8, 10};
  Solution sol = Solution();
  vector<int> ans = sol.getSumAbsoluteDifferences(nums);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}