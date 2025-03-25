#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      pq.push(make_pair(nums[i], i));
    }
    while (k--) {
      auto [val, pos] = pq.top();
      pq.pop();
      nums[pos] = val * multiplier;
      pq.push(make_pair(nums[pos], pos));
    }
    return nums;
  }
};

signed main() {
  vector<int> nums = {2, 1, 3, 5, 6};
  int k = 5, multiplier = 2;
  Solution sol = Solution();
  vector<int> ans = sol.getFinalState(nums, k, multiplier);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}