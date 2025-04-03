#include <iostream>
#include <string>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int numberOfWays(string corridor) {
    int n = corridor.size();
    int cnt = 0;
    long long pre = -1, ans = 1;
    for (int i = 0; i < n; i++) {
      if (corridor[i] == 'S') {
        ++cnt;
        if (cnt >= 3 && cnt % 2) {
          ans = (ans * (i - pre)) % mod;
        }
        pre = i;
      }
    }
    return cnt && cnt % 2 == 0 ? ans : 0;
  }
};

signed main() {
  string corridor = "SSPPSPS";
  Solution sol;
  cout << sol.numberOfWays(corridor) << endl;

  return 0;
}