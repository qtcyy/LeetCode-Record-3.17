#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

vector<int> nums = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

class Solution {
public:
  int numPrimeArrangements(int n) {
    int ord = upper_bound(nums.begin(), nums.end(), n) - nums.begin();
    int rest = n - ord;
    long long ans = 1;
    for (int i = 2; i <= ord; i++) {
      ans = ans * i % mod;
    }
    for (int i = 2; i <= rest; i++) {
      ans = ans * i % mod;
    }
    return ans;
  }
};

signed main() {
  int n = 100;
  Solution sol;
  cout << sol.numPrimeArrangements(n) << endl;

  return 0;
}