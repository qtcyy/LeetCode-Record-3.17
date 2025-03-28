#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSizeSubarray(vector<int> &nums, int target) {
    int n = nums.size();
    vector<long long> pre(n * 2 + 1, 0);
    for (int i = 0; i < n * 2; i++) {
      if (i < n) {
        pre[i + 1] = pre[i] + nums[i];
      } else {
        pre[i + 1] = pre[i] + nums[i - n];
      }
    }
    long long tot = pre[n];
    int delta = target / tot * n, k = target % tot;
    int left = 0, ans = 1e9 + 7;
    for (int i = 0; i < n * 2; i++) {
      while (pre[i + 1] - pre[left] > k) {
        ++left;
      }
      if (pre[i + 1] - pre[left] == k) {
        ans = min(ans, i - left + 1);
      }
    }
    if (ans == 1e9 + 7) {
      return -1;
    }
    return ans + delta;
  }
};

signed main() {
  vector<int> nums = {1, 1, 1, 2, 3};
  int target = 4;
  Solution sol;
  cout << sol.minSizeSubarray(nums, target) << endl;

  return 0;
}