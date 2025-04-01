#include <iostream>
using namespace std;

class Solution {
public:
  int kthFactor(int n, int k) {
    int count = 0, fac = 0;
    for (fac = 1; fac * fac <= n; fac++) {
      if (n % fac == 0) {
        ++count;
        if (count == k) {
          return fac;
        }
      }
    }
    fac--;
    if (fac * fac == n) {
      fac--;
    }
    for (; fac >= 1; fac--) {
      if (n % fac == 0) {
        ++count;
        if (count == k) {
          return n / fac;
        }
      }
    }
    return -1;
  }
};

signed main() {
  int n = 12, k = 3;
  Solution sol;
  cout << sol.kthFactor(n, k) << endl;

  return 0;
}