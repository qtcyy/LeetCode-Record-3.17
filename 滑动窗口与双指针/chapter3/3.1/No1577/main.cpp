#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using LL = long long;
class Solution {
public:
  int numTriplets(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    return solve(a, b) + solve(b, a);
  }

  int solve(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      LL square = 1LL * a[i] * a[i];
      int l = 0, r = m - 1;
      while (l < r) {
        if (square < 1LL * b[l] * b[r])
          r--;
        else if (square > 1LL * b[l] * b[r])
          l++;
        else {
          if (b[l] == b[r]) {
            int c = 0;
            while (l <= r && b[l] == b[r]) {
              l++, c++;
            }
            res += c * (c - 1) / 2;
          } else {
            int c0 = 1, c1 = 1;
            l++, r--;
            while (l <= r && b[l] == b[l - 1])
              l++, c0++;
            while (l <= r && b[r] == b[r + 1])
              r--, c1++;
            res += c0 * c1;
          }
        }
      }
    }
    return res;
  }
};

signed main() {
  vector<int> nums1 = {7, 7, 8, 3}, nums2 = {1, 2, 9, 7};
  Solution sol;
  cout << sol.numTriplets(nums1, nums2) << endl;

  return 0;
}