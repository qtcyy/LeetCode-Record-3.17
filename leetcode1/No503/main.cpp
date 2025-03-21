#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> s;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && nums[s.top()] <= nums[i]) {
        s.pop();
      }
      s.push(i);
    }
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && nums[s.top()] <= nums[i]) {
        s.pop();
      }
      if (!s.empty()) {
        ans[i] = nums[s.top()];
      } else {
        ans[i] = -1;
      }
      s.push(i);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 3, 4, 3};
  Solution sol = Solution();
  vector<int> ans = sol.nextGreaterElements(nums);
  for (auto &num : ans) {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}