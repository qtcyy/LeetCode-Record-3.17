#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    int n = barcodes.size();
    unordered_map<int, int> cnt;
    int mx = 0, mxv = 0;
    for (auto &x : barcodes) {
      ++cnt[x];
      if (cnt[x] > mx) {
        mx = cnt[x];
        mxv = x;
      }
    }
    vector<int> ans(n);
    int i = 0;
    while (mx--) {
      ans[i] = mxv;
      i += 2;
    }
    cnt.erase(mxv);
    for (auto &&[x, c] : cnt) {
      for (int t = 0; t < c; t++) {
        if (i >= n) {
          i = 1;
        }
        ans[i] = x;
        i += 2;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> barcodes = {7, 7, 7, 8, 5, 7, 5, 5, 5, 8};
  Solution sol;
  auto ans = sol.rearrangeBarcodes(barcodes);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}