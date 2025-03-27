#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    double ans = -1e9 + 7;
    for (int i = k - 1; i < n; i++) {
      int sum = pre[i + 1] - pre[i - k + 1];
      ans = max(ans, 1.0 * sum / k);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 4;
  Solution sol;
  cout << sol.findMaxAverage(nums, k) << endl;

  return 0;
}