#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int numKLenSubstrNoRepeats(string s, int k) {
    unordered_map<char, int> cnt;
    int n = s.length(), ans = 0;
    for (int i = 0; i <= n; i++) {
      if (i < k) {
        ++cnt[s[i]];
      } else {
        if (cnt.size() == k) {
          ++ans;
        }
        if (i == n) {
          continue;
        }
        ++cnt[s[i]];
        if (!--cnt[s[i - k]]) {
          cnt.erase(s[i - k]);
        }
      }
    }
    return ans;
  }
};

signed main() {
  string S = "havefunonleetcode";
  int K = 5;
  Solution sol;
  cout << sol.numKLenSubstrNoRepeats(S, K) << endl;

  return 0;
}