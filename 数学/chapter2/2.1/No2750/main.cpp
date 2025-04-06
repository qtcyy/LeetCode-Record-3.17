#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int numberOfGoodSubarraySplits(vector<int> &nums) {
    // [0,1,0,0,1,0,1,1,0,1,0]
    // ans*=i-j
    int n = nums.size();
    int prev = -1, ans = 1;
    for (int i = 0; i < n; i++) {
      if (nums[i]) {
        if (prev != -1) {
          ans = ans * (i - prev) % mod;
        }
        prev = i;
      }
    }
    if (prev == -1) {
      return 0;
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {0, 1, 0, 0, 1};
  Solution sol;
  cout << sol.numberOfGoodSubarraySplits(nums) << endl;

  return 0;
}