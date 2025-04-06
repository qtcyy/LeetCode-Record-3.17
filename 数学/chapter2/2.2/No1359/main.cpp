#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int qpow(long long a, int n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

class Solution {
public:
  int countOrders(int n) {
    int ans = 1;
    int infact2 = qpow(2, mod - 2);
    for (long long i = 2; i <= n * 2; i += 2) {
      ans = ans * i * (i - 1) % mod * infact2 % mod;
    }
    return ans;
  }
};

signed main() {
  int n = 3;
  Solution sol;
  cout << sol.countOrders(n) << endl;

  return 0;
}