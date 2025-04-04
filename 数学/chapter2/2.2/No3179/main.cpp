#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int N = 1005;

vector<ll> fact(N), infact(N);

ll qpow(ll a, ll n) {
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

void init() {
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  infact[N - 1] = qpow(fact[N - 1], mod - 2);
  for (int i = N - 2; i >= 1; i--) {
    infact[i] = infact[i + 1] * (i + 1) % mod;
  }
}

ll C(int a, int b) {
  if (b < 0 || a < b) {
    return 0;
  }
  return fact[a] * infact[b] % mod * infact[a - b] % mod;
}

class Solution {
public:
  int valueAfterKSeconds(int n, int k) {
    init();
    return C(n + k - 1, k);
  }
};

signed main() {
  Solution sol;
  int n = 4, k = 5;
  cout << sol.valueAfterKSeconds(n, k) << endl;

  return 0;
}