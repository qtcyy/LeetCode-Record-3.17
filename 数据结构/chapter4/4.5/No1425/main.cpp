#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> f(n, 0);
    f[0] = nums[0];
    deque<int> deq;
    for (int i = 1; i < n; i++) {
      while (!deq.empty() && f[deq.back()] < f[i - 1]) {
        deq.pop_back();
      }
      deq.push_back(i - 1);
      while (!deq.empty() && deq.front() < i - k) {
        deq.pop_front();
      }
      f[i] = max(0, f[deq.front()]) + nums[i];
    }
    return *max_element(f.begin(), f.end());
  }
};

signed main() {
  vector<int> nums = {10, 2, -10, 5, 20};
  int k = 2;
  Solution sol = Solution();
  cout << sol.constrainedSubsetSum(nums, k) << endl;

  return 0;
}