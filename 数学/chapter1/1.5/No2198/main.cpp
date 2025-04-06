#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long singleDivisorTriplet(vector<int> &nums) {
    vector<int> cnts(101, 0);
    for (int i : nums)
      cnts[i]++;

    long long res = 0;

    for (int i = 1; i <= 100; ++i) {
      for (int j = i; j <= 100; ++j) {
        for (int k = j; k <= 100; ++k) {
          int s = i + j + k;
          if ((s % i == 0) + (s % j == 0) + (s % k == 0) == 1) {
            if (i != j && j != k) {
              res += 6ll * cnts[i] * cnts[j] * cnts[k];
            } else if (i == j) {
              res += 3ll * cnts[i] * (cnts[i] - 1) * cnts[k];
            } else {
              res += 3ll * cnts[i] * cnts[j] * (cnts[j] - 1);
            }
          }
        }
      }
    }

    return res;
  }
};

signed main() {
  vector<int> nums = {4, 6, 7, 3, 2};
  Solution sol;
  cout << sol.singleDivisorTriplet(nums) << endl;

  return 0;
}
