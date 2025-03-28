#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int right = 0, ans = n + 1, sum = 0;
    for (int i = 0; i < n; i++) {
      while (right < n && sum < target) {
        sum += nums[right];
        ++right;
      }
      if (sum < target) {
        break;
      }
      ans = min(ans, right - i);
      sum -= nums[i];
    }
    if (ans == n + 1)
      ans = 0;
    return ans;
  }
};

signed main() {
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  Solution sol;
  cout << sol.minSubArrayLen(target, nums) << endl;

  return 0;
}