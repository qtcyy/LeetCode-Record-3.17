#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxNumberOfAlloys(int n, int k, int budget,
                        vector<vector<int>> &composition, vector<int> &stock,
                        vector<int> &cost) {
    int maxn = ranges::min(stock) + budget + 1;

    int ans = 0;
    for (auto &comp : composition) {
      int l = ans, r = maxn;
      auto check = [&](const int &mid) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
          if (stock[i] < 1ll * comp[i] * mid) {
            sum += (comp[i] * mid - stock[i]) * cost[i];
            if (sum > budget) {
              return false;
            }
          }
        }
        return true;
      };

      while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
          l = mid;
        } else {
          r = mid;
        }
        ans = l;
      }
    }

    return ans;
  }
};

signed main() {
  int n = 2, k = 3, budget = 10;
  vector<vector<int>> composition = {{2, 1}, {1, 2}, {1, 1}};
  vector<int> stock = {1, 1}, cost = {5, 5};
  Solution sol = Solution();
  cout << sol.maxNumberOfAlloys(n, k, budget, composition, stock, cost) << endl;

  return 0;
}