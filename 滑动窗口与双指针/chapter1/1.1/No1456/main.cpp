#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {
    int n = s.length();
    int ans = 0, cur = 0;
    unordered_set<char> un = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < k; i++) {
      if (un.contains(s[i])) {
        ++cur;
      }
    }
    ans = cur;

    int i = 0, j = k - 1;
    while (j + 1 < n) {
      if (un.contains(s[j + 1])) {
        ++cur;
      }
      if (un.contains(s[i])) {
        --cur;
      }
      ans = max(ans, cur);
      ++i;
      ++j;
    }
    return ans;
  }
};

signed main() {
  string s = "leetcode";
  int k = 3;
  Solution sol;
  cout << sol.maxVowels(s, k) << endl;

  return 0;
}