#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int findGCD(vector<int> &nums) {
    auto [x, y] = ranges::minmax(nums);
    int d = gcd(x, y);
    return d;
  }
};

signed main() {
  vector<int> nums = {2, 5, 6, 9, 10};
  Solution sol;
  cout << sol.findGCD(nums) << endl;

  return 0;
}