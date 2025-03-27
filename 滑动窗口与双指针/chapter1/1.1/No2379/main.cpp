#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int n = blocks.length();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + (blocks[i] == 'W');
    }
    int ans = n;
    for (int i = k - 1; i < n; i++) {
      ans = min(ans, pre[i + 1] - pre[i - k + 1]);
    }

    return ans;
  }
};

signed main() {
  string blocks = "WBBWWBBWBW";
  int k = 7;
  Solution sol;
  cout << sol.minimumRecolors(blocks, k) << endl;

  return 0;
}