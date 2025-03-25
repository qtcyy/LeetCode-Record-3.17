#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    const int mod = 1e9 + 7;
    vector<long long> arr;
    long long num = 1;
    while (n) {
      if (n & 1) {
        arr.push_back(num);
      }
      n >>= 1;
      num <<= 1;
    }
    vector<int> ans;
    for (auto &q : queries) {
      int l = q[0], r = q[1];
      long long res = 1;
      for (int i = l; i <= r; i++) {
        res = (res * arr[i]) % mod;
      }
      ans.push_back(res);
    }
    return ans;
  }
};

signed main() {
  int n = 15;
  vector<vector<int>> queries = {{0, 1}, {2, 2}, {0, 3}};
  Solution sol = Solution();
  vector<int> ans = sol.productQueries(n, queries);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}