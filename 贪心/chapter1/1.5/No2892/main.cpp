#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int minArrayLength(vector<int> &nums, int k) {
    if (nums.size() <= 1) {
      return nums.size();
    }
    stack<long long> stk;
    stk.push(1);
    for (auto &x : nums) {
      if (!x) {
        return 1;
      }
      if (stk.top() * x > k) {
        stk.push(x);
      } else {
        stk.top() *= x;
      }
    }
    return stk.size();
  }
};

signed main() {
  vector<int> nums = {2, 3, 3, 7, 3, 5};
  int k = 20;
  Solution sol;
  cout << sol.minArrayLength(nums, k) << endl;

  return 0;
}