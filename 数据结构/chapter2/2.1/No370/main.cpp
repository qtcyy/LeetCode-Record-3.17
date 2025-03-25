#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    vector<int> diff(length + 1, 0);
    for (auto &row : updates) {
      diff[row[0]] += row[2];
      diff[row[1] + 1] -= row[2];
    }
    for (int i = 1; i <= length; i++) {
      diff[i] += diff[i - 1];
    }
    diff.erase(diff.end() - 1);
    return diff;
  }
};

signed main() {
  int length = 5;
  vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
  Solution sol = Solution();
  vector<int> ans = sol.getModifiedArray(length, updates);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}