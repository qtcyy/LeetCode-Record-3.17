#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumCoins(vector<int> &prices) {
    int n = prices.size();
    vector<int> f(n + 2, 0);
    prices.insert(prices.begin(), 0);
    deque<int> deq;
    f[n] = prices[n];
    for (int i = n; i >= 1; i--) {
      while (!deq.empty() && f[deq.back()] > f[i + 1]) {
        deq.pop_back();
      }
      deq.push_back(i + 1);
      while (!deq.empty() && deq.front() > i * 2 + 1) {
        deq.pop_front();
      }
      f[i] = f[deq.front()] + prices[i];
    }
    return f[1];
  }
};

signed main() {
  vector<int> prices = {3, 1, 2};
  Solution sol = Solution();
  cout << sol.minimumCoins(prices) << endl;

  return 0;
}