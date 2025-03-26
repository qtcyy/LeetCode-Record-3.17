#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = costs.size();
    if (candidates * 2 + k > n) {
      ranges::nth_element(costs, costs.begin() + k);
      return accumulate(costs.begin(), costs.begin() + k, 0LL);
    }

    priority_queue<int, vector<int>, greater<>> pre, suf;
    for (int i = 0; i < candidates; i++) {
      pre.push(costs[i]);
      suf.push(costs[n - i - 1]);
    }
    long long ans = 0;
    int i = candidates, j = n - 1 - candidates;
    while (k--) {
      if (pre.top() <= suf.top()) {
        ans += pre.top();
        pre.pop();
        pre.push(costs[i++]);
      } else {
        ans += suf.top();
        suf.pop();
        suf.push(costs[j--]);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
  int k = 3, candidates = 4;
  Solution sol = Solution();
  cout << sol.totalCost(costs, k, candidates) << endl;

  return 0;
}