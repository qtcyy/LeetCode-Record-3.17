#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
  int mirrorReflection(int p, int q) {
    int d = gcd(p, q);
    p /= d;
    p %= 2;
    q /= d;
    q %= 2;
    if (p == 1 && q == 1) {
      return 1;
    }
    return p == 1 ? 0 : 2;
  }
};

signed main() {
  Solution sol;
  int p = 2, q = 1;
  cout << sol.mirrorReflection(p, q) << endl;

  return 0;
}