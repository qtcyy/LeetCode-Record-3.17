#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (!q.empty() && nums[q.back()] <= nums[i]) {
        q.pop_back();
      }
      q.push_back(i);
      while (!q.empty() && q.front() <= i - k) {
        q.pop_front();
      }
      if (i >= k - 1) {
        ans.push_back(nums[q.front()]);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution sol = Solution();
  vector<int> ans = sol.maxSlidingWindow(nums, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}