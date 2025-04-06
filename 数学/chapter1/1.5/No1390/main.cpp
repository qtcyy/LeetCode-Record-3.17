#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int sumFourDivisors(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    auto divide = [&](int p) -> int {
      int res = 0, count = 0, fac = 0;
      for (fac = 1; fac * fac <= p; ++fac) {
        if (p % fac == 0) {
          if (p / fac == fac) {
            res += fac;
            ++count;
          } else {
            res += fac;
            res += p / fac;
            count += 2;
          }
          if (count > 4) {
            return 0;
          }
        }
      }
      if (count != 4) {
        return 0;
      }
      return res;
    };

    for (int i = 0; i < n; i++) {
      ans += divide(nums[i]);
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {21, 4, 7};
  Solution sol;
  cout << sol.sumFourDivisors(nums) << endl;

  return 0;
}