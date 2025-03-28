#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximizeWin(vector<int> &prizePositions, int k) {
    int n = prizePositions.size();
    if (k * 2 + 1 >= prizePositions[n - 1] - prizePositions[0]) {
      return n;
    }
    int ans = 0, mx = 0, left = 0, right = 0;
    for (int mid = 0; mid < n; mid++) {
      while (right < n && prizePositions[right] - prizePositions[mid] <= k) {
        ++right;
      }
      ans = max(ans, mx + right - mid);
      while (prizePositions[mid] - prizePositions[left] > k) {
        ++left;
      }
      mx = max(mx, mid - left + 1);
    }
    return ans;
  }
};

signed main() {
  vector<int> prizePositions = {1, 1, 2, 2, 3, 3, 5};
  int k = 2;
  Solution sol;
  cout << sol.maximizeWin(prizePositions, k) << endl;

  return 0;
}