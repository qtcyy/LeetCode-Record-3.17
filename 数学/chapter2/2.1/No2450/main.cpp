#include <iostream>
#include <string>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

class Solution {
private:
  int qpow(ll a, int n) {
    ll res = 1;
    while (n) {
      if (n & 1) {
        res = res * a % mod;
      }
      a = a * a % mod;
      n >>= 1;
    }
    return res;
  }

public:
  int countDistinctStrings(string s, int k) {
    int n = s.length();
    return qpow(2, n - k + 1);
  }
};

signed main() {
  Solution sol;
  string s = "1001";
  int k = 3;
  cout << sol.countDistinctStrings(s, k) << endl;

  return 0;
}