#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumSumOfHeights(vector<int> &heights) {
    int n = heights.size();
    vector<long long> suf(n + 1);
    stack<int> st;
    st.push(n);
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      int x = heights[i];
      while (st.size() > 1 && x <= heights[st.top()]) {
        int j = st.top();
        st.pop();
        sum -= (long long)heights[j] * (st.top() - j);
      }
      sum += (long long)x * (st.top() - i);
      suf[i] = sum;
      st.push(i);
    }
    long long ans = sum;
    st = stack<int>();
    st.push(-1);
    long long pre = 0;
    for (int i = 0; i < n; i++) {
      int x = heights[i];
      while (st.size() > 1 && x <= heights[st.top()]) {
        int j = st.top();
        st.pop();
        pre -= (long long)heights[j] * (j - st.top());
      }
      pre += (long long)x * (i - st.top());
      ans = max(ans, pre + suf[i + 1]);
      st.push(i);
    }
    return ans;
  }
};

signed main() {
  vector<int> maxHeights = {5, 3, 4, 1, 1};
  Solution *sol = new Solution();
  long long ans = sol->maximumSumOfHeights(maxHeights);
  cout << ans << endl;

  return 0;
}