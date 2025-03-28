#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int n = s.length();
    int cnt[3]{};
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      ++cnt[s[i] - 'a'];
      while (cnt[0] && cnt[1] && cnt[2]) {
        --cnt[s[left++] - 'a'];
      }
      ans += left;
    }

    return ans;
  }
};

signed main() {
  string s = "abcabc";
  Solution sol;
  cout << sol.numberOfSubstrings(s) << endl;

  return 0;
}