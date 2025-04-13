#include <bit>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int selfDivisiblePermutationCount(int n) {
    vector<int> f(1 << n);
    f[0] = 1;
    for (int s = 1; s < 1 << n; s++) {
      int i = popcount((unsigned)s);
      for (int j = 1; j <= n; j++) {
        if (!(s & (1 << (j - 1))))
          continue;
        if (gcd(i, j) == 1)
          f[s] += f[s ^ (1 << (j - 1))];
      }
    }
    return f.back();
  }
};

signed main() {
  Solution sol;
  cout << sol.selfDivisiblePermutationCount(3) << endl;

  return 0;
}