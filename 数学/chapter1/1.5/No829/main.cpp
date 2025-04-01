#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int consecutiveNumbersSum(int n) {
    int ans = 0;
    for (int k = 1; k * k <= 2 * n; k++) {
      ans += (n - (k - 1) * k / 2) % k == 0;
    }
    return ans;
  }
};

signed main() {
  Solution sol;
  cout << sol.consecutiveNumbersSum(15) << endl;

  return 0;
}