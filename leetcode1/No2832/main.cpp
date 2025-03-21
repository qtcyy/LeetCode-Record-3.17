#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maximumLengthOfRanges(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    st.push(-1);
    vector<int> f(n, 0);
    for (int i = 0; i < n; i++) {
      while (st.size() > 1 && nums[st.top()] <= nums[i]) {
        st.pop();
      }
      if (st.top() != -1 && i - st.top() > 1) {
        f[i] += (i - st.top());
      } else if (i - st.top() > 1) {
        f[i] += i;
      }
      st.push(i);
    }
    st = stack<int>();
    st.push(n);
    for (int i = n - 1; i >= 0; i--) {
      while (st.size() > 1 && nums[st.top()] <= nums[i]) {
        st.pop();
      }
      if (st.top() - i > 1) {
        f[i] += st.top() - i;
      } else if (f[i] == 0) {
        f[i] = 1;
      }
      st.push(i);
    }
    return f;
  }
};

signed main() {
  vector<int> nums = {1, 5, 4, 3, 6};
  Solution *sol = new Solution();
  vector<int> ans = sol->maximumLengthOfRanges(nums);
  for (auto &num : ans) {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}