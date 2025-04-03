#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    vector<pair<int, int>> arr;
    int n = difficulty.size();
    for (int i = 0; i < n; i++) {
      arr.emplace_back(difficulty[i], profit[i]);
    }
    ranges::sort(difficulty);
    ranges::sort(arr);
    vector<int> preMax(n + 1, 0);
    for (int i = 0; i < n; i++) {
      preMax[i + 1] = max(preMax[i], arr[i].second);
    }
    int ans = 0;
    for (auto &x : worker) {
      auto it = upper_bound(difficulty.begin(), difficulty.end(), x);
      if (it == difficulty.begin()) {
        continue;
      }
      int pos = it - difficulty.begin();
      cout << pos << endl;
      ans += preMax[pos];
    }
    return ans;
  }
};

signed main() {
  vector<int> difficulty = {2, 4, 6, 8, 10}, profit = {10, 20, 30, 40, 50},
              worker = {4, 5, 6, 7};
  Solution sol;
  cout << sol.maxProfitAssignment(difficulty, profit, worker) << endl;

  return 0;
}