#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

vector<ll> fact(N), infact(N);

ll qpow(ll a, int n) {
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

inline ll C(ll a, ll b) {
  if (b < 0 || a < b) {
    return 0;
  }
  return fact[a] * infact[b] % mod * infact[a - b] % mod;
}

class Solution {
public:
  int countAnagrams(string s) {
    init();
    vector<string> arr;
    stringstream ss(s);
    string word;
    while (ss >> word) {
      arr.push_back(word);
    }
    ll ans = 1;
    for (auto &str : arr) {
      int n = str.size();
      int cnt[26]{};
      for (auto &ch : str) {
        ++cnt[ch - 'a'];
      }
      ll sum = 1;
      for (int i = 0; i < 26; i++) {
        if (!cnt[i])
          continue;
        sum = sum * C(n, cnt[i]) % mod;
        n -= cnt[i];
      }
      ans = ans * sum % mod;
    }
    return ans;
  }
};

signed main() {
  Solution sol;
  string s = "too hot";
  cout << sol.countAnagrams(s) << endl;

  return 0;
}