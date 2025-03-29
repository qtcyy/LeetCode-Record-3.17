#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int n = s.length();
    int cnt0 = 0, cnt1 = 0;
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      cnt0 += (s[i] == '0');
      cnt1 += (s[i] == '1');
      while (cnt0 > k && cnt1 > k) {
        cnt0 -= (s[left] == '0');
        cnt1 -= (s[left] == '1');
        ++left;
      }
      ans += i - left + 1;
    }

    return ans;
  }
};

signed main() {
  string s = "1010101";
  int k = 2;
  Solution sol;
  cout << sol.countKConstraintSubstrings(s, k) << endl;

  return 0;
}