#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int n = s.length();
    int left = 0, ans = 0, cost = 0;
    for (int i = 0; i < n; i++) {
      cost += abs(s[i] - t[i]);
      while (cost > maxCost) {
        cost -= abs(s[left] - t[left]);
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  string s = "abcd", t = "bcdf";
  int maxCost = 3;
  Solution sol;
  cout << sol.equalSubstring(s, t, maxCost) << endl;

  return 0;
}