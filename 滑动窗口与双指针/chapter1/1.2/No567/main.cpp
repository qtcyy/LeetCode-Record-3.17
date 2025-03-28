#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int k = s1.length(), n = s2.length();
    unordered_map<char, int> base;
    for (char &ch : s1) {
      ++base[ch];
    }
    unordered_map<char, int> cnt;
    auto check = [&]() {
      if (cnt.size() != base.size()) {
        return false;
      }
      for (auto &&[ch, val] : cnt) {
        if (!base.contains(ch) || val != base[ch]) {
          return false;
        }
      }
      return true;
    };
    for (int i = 0; i <= n; i++) {
      if (i < k) {
        ++cnt[s2[i]];
      } else {
        // check
        if (check()) {
          return true;
        }

        if (i == n) {
          break;
        }
        ++cnt[s2[i]];
        if (!--cnt[s2[i - k]]) {
          cnt.erase(s2[i - k]);
        }
      }
    }

    return false;
  }
};

signed main() {
  string s1 = "ab", s2 = "eidbaooo";
  Solution sol;
  cout << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl;

  return 0;
}