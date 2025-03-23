#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    vector<int> arr(55, 0);
    for (auto &pos : ranges) {
      arr[pos[0]]++;
      arr[pos[1] + 1]--;
    }
    for (int i = 1; i < 55; i++) {
      arr[i] += arr[i - 1];
    }
    for (int i = left; i <= right; i++) {
      if (!arr[i]) {
        return false;
      }
    }
    return true;
  }
};

signed main() {
  vector<vector<int>> ranges = {{1, 2}, {3, 4}, {5, 6}};
  int left = 2, right = 5;
  Solution sol = Solution();
  cout << sol.isCovered(ranges, left, right) << endl;

  return 0;
}