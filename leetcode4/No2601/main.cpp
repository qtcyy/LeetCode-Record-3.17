#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> pri;
  void init(int n) {
    vector<bool> not_prime(n + 1, false);
    for (int i = 2; i <= n; i++) {
      if (!not_prime[i]) {
        pri.push_back(i);
      }
      for (auto &p : pri) {
        if (i * p > n)
          break;
        not_prime[i * p] = 1;
        if (i % p == 0) {
          break;
        }
      }
    }
  }

public:
  bool primeSubOperation(vector<int> &nums) {
    int pre = 0;
    init(1000);
    pri.insert(pri.begin(), 0);
    for (auto &x : nums) {
      if (x <= pre) {
        return false;
      }
      pre = x - *--lower_bound(pri.begin(), pri.end(), x - pre);
    }
    return true;
  }
};

signed main() {
  vector<int> nums = {4, 9, 6, 10};
  Solution sol = Solution();
  cout << sol.primeSubOperation(nums) << endl;

  return 0;
}