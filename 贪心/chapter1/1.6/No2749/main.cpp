#include <iostream>
using namespace std;

class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    for (long long k = 1; k <= num1 - num2 * k; k++) {
      if (__builtin_popcountll(num1 - num2 * k) <= k) {
        return k;
      }
    }
    return -1;
  }
};

signed main() {
  int num1 = 3, num2 = -2;
  Solution sol;
  cout << sol.makeTheIntegerZero(num1, num2) << endl;

  return 0;
}