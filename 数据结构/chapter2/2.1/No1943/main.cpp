#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
    int mx = 0;
    for (auto &seg : segments) {
      mx = max(mx, max(seg[0], seg[1]));
    }
    vector<long long> arr(mx + 1, 0);
    for (auto &seg : segments) {
      arr[seg[0]] += seg[2];
      arr[seg[1]] -= seg[2];
    }
    int l = 1;
    for (int i = 1; i <= mx; i++) {
      arr[i] += arr[i - 1];
    }
    for (int i = 0; i <= mx; i++) {
      cout << arr[i] << ' ';
    }
    cout << endl;
    vector<vector<long long>> ans;
    for (int i = 2; i <= mx; i++) {
      if (arr[i] != arr[i - 1]) {
        ans.push_back({l, i, arr[i - 1]});
        l = i;
      }
    }

    return ans;
  }
};

signed main() {
  vector<vector<int>> segments = {{1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11}};
  Solution sol = Solution();
  vector<vector<long long>> ans = sol.splitPainting(segments);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}