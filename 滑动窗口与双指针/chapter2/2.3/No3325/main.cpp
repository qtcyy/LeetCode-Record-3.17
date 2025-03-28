#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s, int k) {
    int n = s.length();
    int cnt[26]{};
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      ++cnt[s[i] - 'a'];
      while (cnt[s[i] - 'a'] >= k) {
        --cnt[s[left++] - 'a'];
      }
      ans += left;
    }

    return ans;
  }
};

signed main() {
  string s = "abacb";
  int k = 2;
  Solution sol;
  cout << sol.numberOfSubstrings(s, k) << endl;

  return 0;
}