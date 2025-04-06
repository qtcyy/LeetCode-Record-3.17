#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
  int commonFactors(int a, int b) {
    int d = gcd(a, b);
    int ans = 0;
    for (int i = 1; i * i <= d; i++) {
      if (d % i == 0) {
        ++ans;
        if (i * i < d) {
          ++ans;
        }
      }
    }
    return ans;
  }
};

signed main() {
  int a = 12, b = 6;
  Solution sol;
  cout << sol.commonFactors(a, b) << endl;

  return 0;
}