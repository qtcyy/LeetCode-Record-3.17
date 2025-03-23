#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> arr(1005, 0);
    for (auto &trip : trips) {
      arr[trip[1]] += trip[0];
      arr[trip[2]] -= trip[0];
    }
    for (int i = 0; i < 1004; i++) {
      arr[i + 1] += arr[i];
      if (arr[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};

signed main() {
  vector<vector<int>> trips = {{9, 0, 1}, {3, 3, 7}};
  int capacity = 5;
  Solution sol = Solution();
  cout << sol.carPooling(trips, capacity) << endl;

  return 0;
}