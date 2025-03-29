#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int numberOfSpecialSubstrings(string s) {
    int n = s.length();
    int cnt[26]{};
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      ++cnt[s[i] - 'a'];
      while (cnt[s[i] - 'a'] > 1) {
        --cnt[s[left++] - 'a'];
      }
      ans += i - left + 1;
    }
    return ans;
  }
};

signed main() {
  string s = "abcd";
  Solution sol;
  cout << sol.numberOfSpecialSubstrings(s) << endl;

  return 0;
}