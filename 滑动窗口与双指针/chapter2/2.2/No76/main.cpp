#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.length();
    unordered_map<char, int> cnt, base;
    auto covered = [&]() {
      for (auto &[ch, val] : base) {
        if (!cnt.contains(ch) || cnt[ch] < val) {
          return false;
        }
      }
      return true;
    };
    for (char &ch : t) {
      ++base[ch];
    }
    for (char &ch : s) {
      ++cnt[ch];
    }
    if (!covered()) {
      return "";
    }
    cnt.clear();
    int left = 0;
    string ans = s;
    for (int i = 0; i < n; i++) {
      ++cnt[s[i]];
      int l = 1;
      bool flag = false;
      while (covered()) {
        flag = true;
        if (!--cnt[s[left]]) {
          cnt.erase(s[left]);
        }
        l = ++left;
      }
      --l;
      if (flag) {
        string t = s.substr(l, i - l + 1);
        if (t.size() < ans.size() || t.size() == ans.size() && t < ans) {
          ans = std::move(t);
        }
      }
    }

    return ans;
  }
};

signed main() {
  string s = "ADOBECODEBANC", t = "ABC";
  Solution sol;
  cout << sol.minWindow(s, t) << endl;

  return 0;
}