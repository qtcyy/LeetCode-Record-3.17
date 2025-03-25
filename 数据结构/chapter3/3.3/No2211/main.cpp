#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int countCollisions(string directions) {
    stack<char> st;
    int ans = 0;

    for (auto &ch : directions) {
      if (!st.empty()) {
        if (st.top() == 'R' && ch == 'L') {
          ans += 2;
          st.pop();
          st.push('S');
          //   st.push('S');
        } else if (st.top() == 'S' && ch == 'L') {
          ans++;
          st.push('S');
        } else if (st.top() == 'R' && ch == 'S') {
          ans++;
          st.pop();
          st.push('S');
          //   st.push('S');
        } else {
          st.push(ch);
        }

      } else {
        st.push(ch);
      }
    }
    while (st.size() >= 2) {
      int top = st.top();
      st.pop();
      if (top == 'S' && st.top() == 'R') {
        ans++;
        st.pop();
        st.push('S');
      }
    }
    return ans;
  }
};

signed main() {
  string directions = "SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR";
  Solution sol = Solution();
  cout << sol.countCollisions(directions) << endl;

  return 0;
}