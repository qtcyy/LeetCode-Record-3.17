#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  long long makeSubKSumEqual(vector<int> &arr, int k) {
    int n = arr.size();
    k = gcd(n, k);
    vector<vector<int>> g(k);
    for (int i = 0; i < n; i++) {
      g[i % k].push_back(arr[i]);
    }
    long long ans = 0;
    for (auto &p : g) {
      nth_element(p.begin(), p.begin() + p.size() / 2, p.begin());
      for (auto &x : p) {
        ans += abs(x - p[p.size() / 2]);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> arr = {2, 5, 5, 7};
  int k = 3;
  Solution sol;
  cout << sol.makeSubKSumEqual(arr, k) << endl;

  return 0;
}