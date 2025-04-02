#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int countBeautifulPairs(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    auto getone = [](int x) -> int {
      while (x) {
        if (x / 10 == 0) {
          return x;
        }
        x /= 10;
      }
      return x;
    };
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (gcd(getone(nums[j]), nums[i] % 10) == 1) {
          ++ans;
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {11, 21, 12};
  Solution sol;
  cout << sol.countBeautifulPairs(nums) << endl;

  return 0;
}