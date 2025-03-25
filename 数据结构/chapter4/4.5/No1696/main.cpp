#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxResult(vector<int> &nums, int k) {
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

      f[i] = f[deq.front()] + nums[i];
    }
    return f[n - 1];
  }
};

signed main() {
  vector<int> nums = {1, -1, -2, 4, -7, 3};
  int k = 2;
  Solution sol = Solution();
  cout << sol.maxResult(nums, k) << endl;

  return 0;
}