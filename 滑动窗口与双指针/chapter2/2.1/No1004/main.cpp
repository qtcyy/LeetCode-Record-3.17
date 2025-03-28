#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0, ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (nums[i] == 0);
      while (cnt > k) {
        cnt -= (nums[left] == 0);
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  int K = 3;
  Solution sol;
  cout << sol.longestOnes(nums, K) << endl;

  return 0;
}