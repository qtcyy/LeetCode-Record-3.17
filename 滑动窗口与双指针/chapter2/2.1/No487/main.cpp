#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size();
    int left = 0, ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        ++cnt;
      }
      while (cnt > 1) {
        if (nums[left] == 0) {
          --cnt;
        }
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 0, 1, 1, 0, 1};
  Solution sol;
  cout << sol.findMaxConsecutiveOnes(nums) << endl;

  return 0;
}