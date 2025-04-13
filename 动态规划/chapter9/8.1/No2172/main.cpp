#include <algorithm>
#include <bit>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumANDSum(vector<int> &nums, int numSlots) {
    int n = nums.size();
    vector<int> f(1 << (numSlots * 2));
    for (int i = 0; i < f.size(); i++) {
      int c = popcount((unsigned)i);
      if (c >= n)
        continue;
      for (int j = 0; j < numSlots * 2; j++) {
        if (!(i & (1 << j))) {
          int s = i | (1 << j);
          f[s] = max(f[s], f[i] + ((j / 2 + 1) & nums[c]));
        }
      }
    }
    return ranges::max(f);
  }
};

signed main() {
  vector<int> nums = {1, 3, 10, 4, 7, 1};
  int numSlots = 9;
  Solution sol;
  cout << sol.maximumANDSum(nums, numSlots) << endl;

  return 0;
}