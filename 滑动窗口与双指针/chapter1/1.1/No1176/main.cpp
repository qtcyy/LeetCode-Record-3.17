#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper) {
    int n = calories.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + calories[i];
    }
    int ans = 0;
    for (int i = k - 1; i < n; i++) {
      int val = pre[i + 1] - pre[i - k + 1];
      if (val < lower) {
        --ans;
      } else if (val > upper) {
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> calories = {1, 2, 3, 4, 5};
  int k = 1, lower = 3, upper = 3;
  Solution sol;
  cout << sol.dietPlanPerformance(calories, k, lower, upper) << endl;

  return 0;
}