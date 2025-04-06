#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    unordered_set<int> ban(banned.begin(), banned.end());
    long long sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (ban.contains(i))
        continue;
      sum += i;
      if (sum > maxSum) {
        break;
      }
      ++ans;
    }
    return ans;
  }
};

signed main() {
  vector<int> banned = {1, 6, 5};
  int n = 5, maxSum = 6;
  Solution sol;
  cout << sol.maxCount(banned, n, maxSum) << endl;

  return 0;
}