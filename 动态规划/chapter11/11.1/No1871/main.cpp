#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    if (s.back() == '1')
      return false;
    int n = s.length();
    vector<int> f(n), pre(n);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
      if (i < minJump) {
        pre[i + 1] = pre[i] + f[i];
        continue;
      }
      int l = max(0, i - maxJump), r = i - minJump;
      if (s[i] == '0' && pre[r + 1] - pre[l]) {
        f[i] = 1;
      }
      pre[i + 1] = pre[i] + f[i];
    }
    return f.back();
  }
};

signed main() {
  string s = "011010";
  int minJump = 2, maxJump = 3;
  Solution sol;
  cout << (sol.canReach(s, minJump, maxJump) ? "true" : "false") << endl;

  return 0;
}