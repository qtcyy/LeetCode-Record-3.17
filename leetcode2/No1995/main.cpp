#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    unordered_map<int, int> cnt;
    for (int b = n - 3; b >= 1; b--) {
      for (int d = b + 2; d < n; d++) {
        cnt[nums[d] - nums[b + 1]]++;
      }
      for (int a = 0; a < b; a++) {
        if (int sum = nums[a] + nums[b]; cnt.contains(sum)) {
          ans += cnt[sum];
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 1, 1, 3, 5};
  Solution sol = Solution();

  cout << sol.countQuadruplets(nums);

  return 0;
}