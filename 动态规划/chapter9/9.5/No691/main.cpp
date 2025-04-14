#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minStickers(vector<string> &stickers, string target) {
    int m = stickers.size(), n = target.length();
    vector<vector<int>> cnt(m, vector<int>(26));
    for (int i = 0; i < m; i++) {
      for (char &ch : stickers[i]) {
        ++cnt[i][ch - 'a'];
      }
    }
    vector<int> f(1 << n, INT_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < 1 << n; i++) {
      if (f[i] == INT_MAX / 2)
        continue;

      for (int k = 0; k < m; k++) {
        int nxt = i;
        vector<int> left(cnt[k]);
        for (int j = 0; j < n; j++) {
          if (i >> j & 1)
            continue;
          if (left[target[j] - 'a']) {
            --left[target[j] - 'a'];
            nxt |= 1 << j;
          }
        }
        f[nxt] = min(f[nxt], f[i] + 1);
      }
    }
    return f.back() == (INT_MAX / 2) ? -1 : f.back();
  }
};

signed main() {
  vector<string> stickers = {"with", "example", "science"};
  string target = "thehat";
  Solution sol;
  cout << sol.minStickers(stickers, target) << endl;

  return 0;
}