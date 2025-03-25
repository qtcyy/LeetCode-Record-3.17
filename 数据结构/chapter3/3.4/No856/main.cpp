#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);
    for (auto &ch : s) {
      if (ch == '(') {
        st.push(0);
      } else {
        int val = st.top();
        st.pop();
        st.top() += max(val * 2, 1);
      }
    }
    return st.top();
  }
};

signed main() {
  string s = "(()(()))";
  Solution sol = Solution();
  cout << sol.scoreOfParentheses(s) << endl;

  return 0;
}