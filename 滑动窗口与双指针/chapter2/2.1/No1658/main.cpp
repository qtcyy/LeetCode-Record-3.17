#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size();
    long long all = accumulate(nums.begin(), nums.end(), 0LL);
    int target = all - x;
    int left = 0, len = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += nums[i];
      while (cnt > target) {
        cnt -= nums[left];
        ++left;
      }
      if (cnt == target) {
        len = max(len, i - left + 1);
      }
    }
    if (len == 0 && all != x) {
      return -1;
    }

    return n - len;
  }
};

signed main() {
  vector<int> nums = {3, 2, 20, 1, 1, 3};
  int x = 10;
  Solution sol;
  cout << sol.minOperations(nums, x) << endl;

  return 0;
}