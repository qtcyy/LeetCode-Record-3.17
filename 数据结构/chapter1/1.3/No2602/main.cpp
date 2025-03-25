#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<long long> minOperations(vector<int> &nums, vector<int> &queries) {
    ranges::sort(nums);
    int n = nums.size();
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    vector<long long> ans;
    for (auto &q : queries) {
      long long i = ranges::lower_bound(nums, q) - nums.begin();
      long long left = i * nums[i] - pre[i];
      long long right = pre.back() - pre[i] - (n - i) * nums[i];
      ans.push_back(left + right);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {3, 1, 6, 8}, queries = {1, 5};
  Solution sol = Solution();
  vector<long long> ans = sol.minOperations(nums, queries);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}