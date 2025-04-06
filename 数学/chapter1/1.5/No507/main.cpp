#include <iostream>
using namespace std;

class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num <= 1) {
      return false;
    }
    int sum = 0, fac = 0;
    for (fac = 1; fac * fac <= num; ++fac) {
      if (num % fac == 0) {
        sum += fac;
      }
    }
    --fac;
    if (fac * fac == num) {
      --fac;
    }
    for (; fac >= 2; --fac) {
      if (num % fac == 0) {
        sum += num / fac;
      }
    }
    return sum == num;
  }
};

signed main() {
  Solution sol;
  cout << (sol.checkPerfectNumber(28) ? "true" : "false") << endl;

  return 0;
}