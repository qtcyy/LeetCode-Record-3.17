#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int addMinimum(string word) {
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    int i = 0, n = word.length();
    while (i < n) {
      int val = (st.top() - 96) % 3;
      if (val == word[i] - 'a') {
        st.push(word[i++]);
      } else {
        st.push((st.top() - 96) % 3 + 97);
      }
    }
    int cur = st.size() + 'c' - st.top();

    return cur - n - 3;
  }
};

signed main() {
  string word = "aaa";
  Solution sol;
  cout << sol.addMinimum(word) << endl;

  return 0;
}