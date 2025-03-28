#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int cnt = 0;
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (!nums[i]) {
        ++cnt;
      }
      while (cnt > 1) {
        if (!nums[left]) {
          --cnt;
        }
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans - 1;
  }
};

signed main() {
  vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  Solution sol;
  cout << sol.longestSubarray(nums) << endl;

  return 0;
}