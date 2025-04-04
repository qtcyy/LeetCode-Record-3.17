#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    bool flag = false;
    int ans = 0;
    for (auto &x : nums) {
      if (!x && !flag || x && flag) {
        ++ans;
        flag = !flag;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {0, 1, 1, 0, 1};
  Solution sol;
  cout << sol.minOperations(nums) << endl;

  return 0;
}