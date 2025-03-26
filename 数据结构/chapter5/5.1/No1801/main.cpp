#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> sell;
    priority_queue<pair<int, int>> buy;
    for (auto &d : orders) {
      int price = d[0], amount = d[1], type = d[2];
      if (type == 0) {
        while (amount && !sell.empty() && sell.top().first <= price) {
          auto [p, a] = sell.top();
          sell.pop();
          if (amount >= a) {
            amount -= a;
          } else {
            sell.emplace(p, a - amount);
            amount = 0;
          }
        }
        if (amount) {
          buy.emplace(price, amount);
        }
      } else {
        while (amount && !buy.empty() && buy.top().first >= price) {
          auto [p, a] = buy.top();
          buy.pop();
          if (amount >= a) {
            amount -= a;
          } else {
            buy.emplace(p, a - amount);
            amount = 0;
          }
        }
        if (amount) {
          sell.emplace(price, amount);
        }
      }
    }
    int ans = 0;
    while (!buy.empty()) {
      ans = (ans + buy.top().second) % mod;
      buy.pop();
    }
    while (!sell.empty()) {
      ans = (ans + sell.top().second) % mod;
      sell.pop();
    }

    return ans;
  }
};

signed main() {
  vector<vector<int>> orders = {{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}};
  Solution sol = Solution();
  cout << sol.getNumberOfBacklogOrders(orders) << endl;

  return 0;
}