#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      if (!nums[i]) {
        ++ans;
        for (int j = i; j <= i + 2; j++) {
          nums[j] = 1 - nums[j];
        }
      }
    }
    for (auto &x : nums) {
      if (!x) {
        return -1;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {0, 1, 1, 1, 0, 0};
  Solution sol;
  cout << sol.minOperations(nums) << endl;

  return 0;
}