#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int n = nums.size();
    ranges::sort(nums);
    int per = accumulate(nums.begin(), nums.end(), 0);
    if (nums.back() > per || per % k) {
      return false;
    }
    per /= k;
    vector<bool> f(1 << n);
    f[0] = 1;
    vector<int> rec(1 << n);
    for (int s = 0; s < 1 << n; s++) {
      if (!f[s])
        continue;
      for (int i = 0; i < n; i++) {
        if (nums[i] + rec[s] > per)
          break;
        if (s >> i & 1)
          continue;
        int nxt = s | (1 << i);
        if (!f[nxt]) {
          rec[nxt] = (nums[i] + rec[s]) % per;
          f[nxt] = true;
        }
      }
    }
    return f.back();
  }
};

signed main() {
  vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
  int k = 4;
  Solution sol;
  cout << (sol.canPartitionKSubsets(nums, k) ? "true" : "false") << endl;

  return 0;
}