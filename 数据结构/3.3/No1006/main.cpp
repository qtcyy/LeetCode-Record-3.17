#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int clumsy(int n) {
    stack<int> st;
    st.push(n);
    n--;
    int cnt = 0;

    while (n > 0) {
      if (cnt % 4 == 0) {
        st.top() *= n;
      } else if (cnt % 4 == 1) {
        st.top() /= n;
      } else if (cnt % 4 == 2) {
        st.push(n);
      } else {
        st.push(-n);
      }
      cnt++;
      n--;
    }
    int ans = 0;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }

    return ans;
  }
};

signed main() {
  int n = 10;
  Solution sol = Solution();
  cout << sol.clumsy(n) << endl;

  return 0;
}