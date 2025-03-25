#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumPopulation(vector<vector<int>> &logs) {
    vector<int> arr(3000, 0);
    for (auto &pos : logs) {
      arr[pos[0]]++;
      arr[pos[1]]--;
    }
    for (int i = 1950; i <= 2050; i++) {
      arr[i] += arr[i - 1];
    }
    int ans = 0, maxn = 0;
    for (int i = 1950; i <= 2050; i++) {
      if (arr[i] > maxn) {
        maxn = arr[i];
        ans = i;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> logs = {{2008, 2026}, {2004, 2008}, {2034, 2035},
                              {1999, 2050}, {2049, 2050}, {2011, 2035},
                              {1966, 2033}, {2044, 2049}};
  Solution sol = Solution();
  cout << sol.maximumPopulation(logs) << endl;

  return 0;
}