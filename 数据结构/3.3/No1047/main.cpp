#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string removeDuplicates(string s) {
    int n = s.length();
    stack<char> st;
    for (char &ch : s) {
      if (!st.empty() && ch == st.top()) {
        st.pop();
      } else {
        st.push(ch);
      }
    }
    string ans = "";
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

signed main() {
  string s = "abbaca";
  Solution sol = Solution();
  cout << sol.removeDuplicates(s) << endl;

  return 0;
}