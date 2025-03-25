#include <iostream>
using namespace std;

class Solution {
public:
  string removeOuterParentheses(string s) {
    string ans, st;
    int n = s.length(), pos = 0;
    for (int i = 0; i < n; i++) {
      ans.push_back(s[i]);
      if (st.size() && s[i] == ')' && st.back() == '(') {
        st.pop_back();
        if (!st.size()) {
          ans.erase(pos, 1);
          ans.pop_back();
          pos = ans.size();
        }
      } else {
        st.push_back(s[i]);
      }
    }
    return ans;
  }
};

signed main() {
  string s = "(()())(())(()(()))";
  Solution sol = Solution();
  cout << sol.removeOuterParentheses(s) << endl;

  return 0;
}