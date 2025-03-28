#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int n = s.length(), k = p.length();
    unordered_map<char, int> base;
    for (char &ch : p) {
      ++base[ch];
    }
    unordered_map<char, int> cnt;
    vector<int> ans;

    auto check = [&]() {
      if (base.size() != cnt.size()) {
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
        ++cnt[s[i]];
      } else {
        if (check()) {
          ans.push_back(i - k);
        }
        if (i == n)
          break;
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
  string s = "cbaebabacd", p = "abc";
  Solution sol;
  vector<int> ans = sol.findAnagrams(s, p);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}