#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool makesquare(vector<int> &matchsticks) {
    int n = matchsticks.size();
    ranges::sort(matchsticks);
    int per = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (per % 4)
      return false;
    per /= 4;
    if (matchsticks.back() > per)
      return false;
    vector<bool> rec(1 << n, false);
    for (int s = 1; s < 1 << n; s++) {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        if (s >> i & 1) {
          sum += matchsticks[i];
        }
      }
      if (sum == per)
        rec[s] = 1;
    }
    for (int s = 1; s < 1 << n; s++) {
      for (int j = s; j; j = s & (j - 1)) {
        rec[s] = rec[s] | (rec[s ^ j] & rec[j]);
      }
    }
    return rec.back();
  }
};

class Solution2 {
public:
  bool makesquare(vector<int> &matchsticks) {
    int n = matchsticks.size();
    int tot = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (tot % 4) {
      return false;
    }
    int per = tot / 4;
    ranges::sort(matchsticks);
    if (matchsticks.back() > per)
      return false;
    vector<int> f(1 << n, -1);
    f[0] = 0;
    for (int s = 0; s < 1 << n; s++) {
      if (f[s] == -1)
        continue;
      for (int i = 0; i < n; i++) {
        if (f[s] + matchsticks[i] > per)
          break;
        if (s >> i & 1)
          continue;
        int nxt = s | 1 << i;
        f[nxt] = (matchsticks[i] + f[s]) % per;
      }
    }
    return f.back() == 0;
  }
};

signed main() {
  vector<int> matchsticks = {5, 5, 5, 5, 8, 4, 4, 4, 4, 4, 3, 3, 3, 3, 4};
  Solution2 sol;
  cout << (sol.makesquare(matchsticks) ? "true" : "false") << endl;

  return 0;
}