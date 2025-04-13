#include <bit>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumXORSum(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<int> f(1 << n, INT_MAX);
    f[0] = 0;
    for (int s = 1; s < 1 << n; s++) {
      int i = popcount((unsigned)s) - 1;
      for (int j = 0; j < n; j++) {
        if (s >> j & 1) {
          f[s] = min(f[s], f[s ^ (1 << j)] + (nums1[i] ^ nums2[j]));
        }
      }
    }

    return f.back();
  }
};

signed main() {
  vector<int> nums1 = {1, 0, 3}, nums2 = {5, 3, 4};
  Solution sol;
  cout << sol.minimumXORSum(nums1, nums2) << endl;

  return 0;
}