#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
private:
  long long qpow(long long a, long long n) {
    long long res = 1;
    while (n) {
      if (n & 1) {
        res = (res * a) % mod;
      }
      a = (a * a) % mod;
      n >>= 1;
    }
    return res;
  }

public:
  int countGoodNumbers(long long n) {
    // 5^even+4^odd
    long long even = (n + 1) / 2;
    long long odd = n / 2;
    return (qpow(5, even) * qpow(4, odd)) % mod;
  }
};

signed main() {
  Solution sol;
  cout << sol.countGoodNumbers(200000000000345) << endl;

  return 0;
}