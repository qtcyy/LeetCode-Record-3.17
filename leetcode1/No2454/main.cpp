#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> secondGreaterElement(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && nums[st.top()] <= nums[i]) {
        st.pop();
      }
      if (!st.empty() && st.size() > 1) {
        int temp = st.top();
        st.pop();
        ans[i] = nums[st.top()];
        st.push(temp);
      } else {
        ans[i] = -1;
      }
      st.push(i);
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 4, 0, 9, 6};
  Solution *sol = new Solution();
  vector<int> ans = sol->secondGreaterElement(nums);
  delete sol;
  for (auto &num : ans) {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}