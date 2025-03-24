#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int minDeletion(vector<int> &nums) {
    stack<int> st;
    int ans = 0;
    for (auto &x : nums) {
      if (!st.empty() && st.size() % 2) {
        if (st.top() == x) {
          st.pop();
          ans++;
        }
      }
      st.push(x);
    }
    return ans + (st.size() & 1);
  }
};

signed main() {
  vector<int> nums = {1, 1, 2, 2, 5, 5};
  Solution sol = Solution();
  cout << sol.minDeletion(nums) << endl;

  return 0;
}