#include <iostream>
#include <string>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int numWays(string s) {
    // count
    int cnt = 0;
    int n = s.length();
    for (auto &ch : s) {
      if (ch == '1') {
        ++cnt;
      }
    }
    if (cnt % 3) {
      return 0;
    }
    if (cnt == 0) {
      return 1ll * (n - 1) * (n - 2) / 2 % mod;
    }
    cnt /= 3;
    long long ans1 = 0, ans2 = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (s[i] == '1');
      if (sum == cnt) {
        ++ans1;
      } else if (sum > cnt) {
        break;
      }
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      sum += (s[i] == '1');
      if (sum == cnt) {
        ++ans2;
      } else if (sum > cnt) {
        break;
      }
    }
    return (ans1 * ans2) % mod;
  }
};

signed main() {
  string s = "10101";
  Solution sol;
  cout << sol.numWays(s) << endl;

  return 0;
}