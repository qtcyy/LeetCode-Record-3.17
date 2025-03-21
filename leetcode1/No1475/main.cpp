#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    // 方法二：单调栈
    stack<int> s;
    int n = prices.size();
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && prices[s.top()] > prices[i]) {
        s.pop();
      }
      if (!s.empty()) {
        ans[i] = prices[i] - prices[s.top()];
      } else {
        ans[i] = prices[i];
      }
      s.push(i);
    }
    return ans;
  }
};

signed main() {
  vector<int> prices = {8, 4, 6, 2, 3};
  Solution sol = Solution();
  vector<int> ans = sol.finalPrices(prices);
  for (int &num : ans) {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}