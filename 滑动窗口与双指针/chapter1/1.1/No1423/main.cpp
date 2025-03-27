#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + cardPoints[i];
    }
    if (k == n) {
      return pre.back();
    }
    int mx = pre.back();
    int len = n - k;
    for (int i = len - 1; i < n; i++) {
      mx = min(mx, pre[i + 1] - pre[i - len + 1]);
    }

    return pre.back() - mx;
  }
};

signed main() {
  vector<int> cardPoints = {1, 79, 80, 1, 1, 1, 200, 1};
  int k = 3;
  Solution sol;
  cout << sol.maxScore(cardPoints, k) << endl;

  return 0;
}