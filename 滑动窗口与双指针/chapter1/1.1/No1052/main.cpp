#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int n = grumpy.size();
    vector<int> prea(n + 1, 0), preb(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prea[i + 1] = prea[i] + customers[i];
      if (grumpy[i]) {
        preb[i + 1] = preb[i];
      } else {
        preb[i + 1] = preb[i] + customers[i];
      }
    }
    int mx = 0;
    for (int i = minutes - 1; i < n; i++) {
      mx = max(mx, prea[i + 1] - prea[i - minutes + 1] - preb[i + 1] +
                       preb[i - minutes + 1]);
    }
    return preb.back() + mx;
  }
};

signed main() {
  vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5},
              grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
  int minutes = 3;
  Solution sol;
  cout << sol.maxSatisfied(customers, grumpy, minutes) << endl;

  return 0;
}