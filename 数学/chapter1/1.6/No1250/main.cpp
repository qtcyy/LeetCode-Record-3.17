#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool isGoodArray(vector<int> &nums) {
    int all = 0;
    for (int &x : nums) {
      all = gcd(x, all);
      if (all == 1) {
        return true;
      }
    }
    return false;
  }
};

signed main() {
  vector<int> nums = {12, 5, 7, 23};
  Solution sol;
  cout << (sol.isGoodArray(nums) ? "true" : "false") << endl;

  return 0;
}