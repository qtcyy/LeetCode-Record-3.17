#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int maximumGain(string s, int x, int y) {
    int ans = 0;
    if (x >= y) {
      stack<char> st;
      for (auto &ch : s) {
        if (ch == 'b' && !st.empty() && st.top() == 'a') {
          st.pop();
          ans += x;
        } else {
          st.push(ch);
        }
      }
      string str = "";
      while (!st.empty()) {
        str = st.top() + str;
        st.pop();
      }
      for (char &ch : str) {
        if (ch == 'a' && !st.empty() && st.top() == 'b') {
          st.pop();
          ans += x;
        } else {
          st.push(ch);
        }
      }
    } else {
      stack<char> st;
      for (auto &ch : s) {
        if (ch == 'a' && !st.empty() && st.top() == 'b') {
          st.pop();
          ans += y;
        } else {
          st.push(ch);
        }
      }
      string str = "";
      while (!st.empty()) {
        str = st.top() + str;
        st.pop();
      }
      for (char &ch : str) {
        if (ch == 'b' && !st.empty() && st.top() == 'a') {
          st.pop();
          ans += x;
        } else {
          st.push(ch);
        }
      }
    }
    return ans;
  }
};

signed main() {
  string s = "cdbcbbaaabab";
  int x = 4, y = 5;
  Solution sol = Solution();
  cout << sol.maximumGain(s, x, y) << endl;

  return 0;
}