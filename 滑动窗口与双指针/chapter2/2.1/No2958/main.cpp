#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0, ans = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      ++cnt[nums[i]];
      while (cnt[nums[i]] > k) {
        --cnt[nums[left]];
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
  int k = 2;
  Solution sol;
  cout << sol.maxSubarrayLength(nums, k) << endl;

  return 0;
}