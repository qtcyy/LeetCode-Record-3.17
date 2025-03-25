#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  string reverseParentheses(string s) {
    stack<string> st;
    string res;
    for (auto &ch : s) {
      if (ch == '(') {
        st.push(res);
        res = "";
      } else if (ch == ')') {
        reverse(res.begin(), res.end());
        res = st.top() + res;
        st.pop();
      } else {
        res.push_back(ch);
      }
    }
    return res;
  }
};

signed main() {
  string s = "(ed(et(oc))el)";
  Solution sol = Solution();
  cout << sol.reverseParentheses(s) << endl;

  return 0;
}