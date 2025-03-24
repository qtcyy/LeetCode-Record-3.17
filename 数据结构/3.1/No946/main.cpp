#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> st;
    int idx = 0;
    for (auto &x : pushed) {
      st.push(x);
      while (!st.empty() && st.top() == popped[idx]) {
        idx++;
        st.pop();
      }
    }
    return st.size() == 0;
  }
};

signed main() {
  vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
  Solution sol = Solution();
  cout << sol.validateStackSequences(pushed, popped) << endl;

  return 0;
}