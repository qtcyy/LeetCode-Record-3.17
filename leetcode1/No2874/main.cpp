#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    vector<int> preMax(n, 0), sufMax(n, 0);
    preMax[0] = nums[0];
    sufMax[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      preMax[i] = max(preMax[i - 1], nums[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
      sufMax[i] = max(sufMax[i + 1], nums[i]);
    }
    long long ans = 0;
    for (int i = 1; i < n - 1; i++) {
      long long val = 1ll * (preMax[i - 1] - nums[i]) * sufMax[i + 1];
      ans = max(ans, val);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 10, 3, 4, 19};

  Solution sol = Solution();
  cout << sol.maximumTripletValue(nums) << endl;

  return 0;
}