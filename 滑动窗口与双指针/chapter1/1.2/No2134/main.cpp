#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(2 * n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
    for (int i = n; i < 2 * n; i++) {
      pre[i + 1] = pre[i] + nums[i - n];
    }
    int k = pre[n];
    int ans = 0;
    for (int i = k - 1; i < 2 * n; i++) {
      ans = max(ans, pre[i + 1] - pre[i - k + 1]);
    }

    return k - ans;
  }
};

signed main() {
  vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 1, 0};
  Solution sol;
  cout << sol.minSwaps(nums) << endl;

  return 0;
}