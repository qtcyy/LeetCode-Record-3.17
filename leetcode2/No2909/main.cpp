#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> preMin(n, 0), sufMin(n, 0);
    preMin[0] = nums[0];
    sufMin[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      preMin[i] = min(preMin[i - 1], nums[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
      sufMin[i] = min(sufMin[i + 1], nums[i]);
    }
    const int INF = 0x3f3f3f3f;
    int ans = INF;
    for (int i = 1; i < n - 1; i++) {
      if (preMin[i - 1] >= nums[i] || sufMin[i + 1] >= nums[i]) {
        continue;
      }
      ans = min(ans, preMin[i - 1] + nums[i] + sufMin[i + 1]);
    }
    return ans == INF ? -1 : ans;
  }
};

signed main() {
  vector<int> nums = {6, 5, 4, 3, 4, 5};
  Solution sol = Solution();
  cout << sol.minimumSum(nums) << endl;

  return 0;
}