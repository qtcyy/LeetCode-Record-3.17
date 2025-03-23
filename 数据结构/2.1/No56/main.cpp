#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int mx = 0, mn = 1e5;
    for (auto &item : intervals) {
      mx = max(mx, item[1]);
      mn = min(mn, item[0]);
    }
    vector<int> arr(mx + 2, 0);
    for (auto &item : intervals) {
      arr[item[0]]++;
      arr[item[1] + 1]--;
    }
    vector<vector<int>> ans;
    int l = -1;
    for (int i = 1; i <= mx + 1; i++) {
      arr[i] += arr[i - 1];
      if (l == -1 && arr[i]) {
        l = i;
      } else if (!arr[i] && l != -1) {
        ans.push_back({l, i - 1});
        l = -1;
      }
    }
    for (int i = 0; i <= mx + 1; i++) {
      cout << arr[i] << ' ';
    }
    cout << endl;
    return ans;
  }
};

signed main() {
  vector<vector<int>> intervals = {{1, 4}, {5, 6}};
  Solution sol = Solution();
  vector<vector<int>> ans = sol.merge(intervals);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}