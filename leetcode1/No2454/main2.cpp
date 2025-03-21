#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> secondGreaterElement(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    for (int i = 0; i < n; i++) {
      while (!q.empty() && q.top().first < nums[i]) {
        ans[q.top().second] = nums[i];
        q.pop();
      }
      while (!st.empty() && nums[st.top()] < nums[i]) {
        q.push({nums[st.top()], st.top()});
        st.pop();
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
  for (auto &num : ans) {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}