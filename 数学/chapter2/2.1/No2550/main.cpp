#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
private:
  long long qpow(long long a, int n) {
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
  int monkeyMove(int n) { return (qpow(2, n) - 2 + mod) % mod; }
};

signed main() {
  Solution sol;
  cout << sol.monkeyMove(4) << endl;

  return 0;
}