#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
  string shortestBeautifulSubstring(string s, int k) {
    if (ranges::count(s, '1') < k) {
      return "";
    }
    int n = s.length();
    int left = 0, cnt = 0;
    string ans = s;
    for (int i = 0; i < n; i++) {
      cnt += s[i] - '0';
      while (cnt > k || s[left] == '0') {
        cnt -= s[left] - '0';
        ++left;
      }
      if (cnt == k) {
        string t = s.substr(left, i - left + 1);
        if (t.length() < ans.length() ||
            t.length() == ans.length() && t < ans) {
          ans = std::move(t);
        }
      }
    }

    return ans;
  }
};

signed main() {
  string s = "100011001";
  int k = 3;
  Solution sol;
  cout << sol.shortestBeautifulSubstring(s, k) << endl;

  return 0;
}