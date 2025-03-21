#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_set<int> cnt;
  void breakdown(int n) {
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        while (n % i == 0) {
          n /= i;
        }
        cnt.insert(i);
      }
    }
    if (n != 1) {
      cnt.insert(n);
    }
  }

public:
  int distinctPrimeFactors(vector<int> &nums) {
    for (auto &x : nums) {
      breakdown(x);
    }
    return cnt.size();
  }
};

signed main() {
  vector<int> nums = {2, 4, 3, 7, 10, 6};
  Solution sol = Solution();
  cout << sol.distinctPrimeFactors(nums) << endl;

  return 0;
}