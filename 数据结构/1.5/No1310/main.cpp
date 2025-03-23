#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] ^ arr[i];
    }
    vector<int> res;
    for (auto &q : queries) {
      res.push_back(pre[q[1] + 1] ^ pre[q[0]]);
    }
    return res;
  }
};

signed main() {
  vector<int> arr = {1, 3, 4, 8};
  vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
  Solution sol = Solution();
  vector<int> ans = sol.xorQueries(arr, queries);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}