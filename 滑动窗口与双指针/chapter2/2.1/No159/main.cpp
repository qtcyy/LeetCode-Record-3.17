#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.length();
    unordered_map<char, int> cnt;
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      ++cnt[s[i]];
      while (cnt.size() > 2) {
        if (!--cnt[s[left]]) {
          cnt.erase(s[left]);
        }
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  string s = "ccaabbb";
  Solution sol;
  cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;

  return 0;
}