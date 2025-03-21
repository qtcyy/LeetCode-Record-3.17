#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    // (arr[i]-arr[j-1])%k==0
    int m = nums.size();
    if (m < 2) {
      return false;
    }
    unordered_map<int, int> mp;
    mp[0] = -1;
    int remainder = 0;
    for (int i = 0; i < m; i++) {
      remainder = (remainder + nums[i]) % k;
      if (mp.count(remainder)) {
        int prevIndex = mp[remainder];
        if (i - prevIndex >= 2) {
          return true;
        }
      } else {
        mp[remainder] = i;
      }
    }
    return false;
  }
};

signed main() {
  vector<int> nums = {23, 2, 4, 6, 7};
  int k = 6;
  Solution sol = Solution();
  cout << sol.checkSubarraySum(nums, k) << endl;

  return 0;
}