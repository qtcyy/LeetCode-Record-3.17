#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string smallestNumber(string pattern) {
    int n = pattern.size();
    char cur = '1';
    string ans(n + 1, 0);
    int i = 0;
    while (i < n) {
      if (i && pattern[i] == 'I')
        ++i;
      for (; i < n && pattern[i] == 'I'; ++i)
        ans[i] = cur++;
      int i0 = i;
      while (i < n && pattern[i] == 'D')
        ++i;
      for (int j = i; j >= i0; j--)
        ans[j] = cur++;
    }
    return ans;
  }
};

signed main() {
  string pattern = "IIIDIDDD";
  Solution sol;
  cout << sol.smallestNumber(pattern) << endl;

  return 0;
}