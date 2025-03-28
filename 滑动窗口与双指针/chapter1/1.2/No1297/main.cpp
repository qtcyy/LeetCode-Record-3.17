#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int n = s.length(), ans = 0;
    auto process = [&](const int len) {
      unordered_map<char, int> cnt;
      unordered_map<string, int> sum;
      for (int i = 0; i <= n; i++) {
        if (i < len) {
          ++cnt[s[i]];
        } else {
          if (cnt.size() <= maxLetters) {
            ++sum[s.substr(i - len, len)];
          }
          if (i == n) {
            break;
          }
          ++cnt[s[i]];
          if (!--cnt[s[i - len]]) {
            cnt.erase(s[i - len]);
          }
        }
      }
      for (auto &&[str, val] : sum) {
        cout << str << endl;
        ans = max(ans, val);
      }
    };
    for (int len = minSize; len <= maxSize; len++) {
      process(len);
    }

    return ans;
  }
};

signed main() {
  string s = "aababcaab";
  int maxLetters = 2, minSize = 3, maxSize = 4;
  Solution sol;
  cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;

  return 0;
}