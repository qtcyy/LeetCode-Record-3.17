#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int takeCharacters(string s, int k) {
    int n = s.length();
    vector<int> tot(3, 0);
    for (char &ch : s) {
      ++tot[ch - 'a'];
    }
    if (tot[0] < k || tot[1] < k || tot[2] < k) {
      return -1;
    }
    vector<int> target = {tot[0] - k, tot[1] - k, tot[2] - k};
    vector<int> cnt(3, 0);
    int left = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      ++cnt[s[i] - 'a'];
      while (cnt[s[i] - 'a'] > target[s[i] - 'a']) {
        --cnt[s[left] - 'a'];
        ++left;
      }
      ans = max(ans, i - left + 1);
    }
    return n - ans;
  }
};

signed main() {
  string s = "aabaaaacaabc";
  int k = 2;
  Solution sol;
  cout << sol.takeCharacters(s, k) << endl;

  return 0;
}