#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
  int smallestEvenMultiple(int n) {
    int d = gcd(2, n);
    return 2 * n / d;
  }
};

signed main() {
  Solution sol;
  cout << sol.smallestEvenMultiple(6) << endl;

  return 0;
}