#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, vector<int> &numsDivide) {
    ranges::sort(nums);
    int d = numsDivide[0], n = numsDivide.size();
    for (int i = 1; i < n; i++) {
      d = gcd(d, numsDivide[i]);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (d % nums[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};

signed main() {
  vector<int> nums = {2, 3, 2, 4, 3}, numsDivide = {9, 6, 9, 3, 15};
  Solution sol;
  cout << sol.minOperations(nums, numsDivide) << endl;

  return 0;
}