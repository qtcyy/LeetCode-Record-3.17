#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &data) {
    int n = data.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + data[i];
    }
    int k = pre.back();
    int mx = 0;
    for (int i = k - 1; i < n; i++) {
      mx = max(mx, pre[i + 1] - pre[i - k + 1]);
    }

    return k - mx;
  }
};

signed main() {
  vector<int> data = {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0,
                      1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1};
  Solution sol;
  cout << sol.minSwaps(data) << endl;

  return 0;
}