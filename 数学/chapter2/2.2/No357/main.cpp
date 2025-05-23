#include <iostream>
using namespace std;

class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return 10;
    }
    int ans = 10, cur = 9;
    for (int i = 0; i < n - 1; i++) {
      cur *= (9 - i);
      ans += cur;
    }
    return ans;
  }
};

signed main() {
  int n = 2;
  Solution sol;
  cout << sol.countNumbersWithUniqueDigits(n) << endl;

  return 0;
}