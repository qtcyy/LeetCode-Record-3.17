#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> not_prime(n + 1, false);
    vector<int> pri;
    for (int i = 2; i < n; ++i) {
      if (!not_prime[i]) {
        pri.push_back(i);
      }
      for (int &p : pri) {
        if (i * p > n) {
          break;
        }
        not_prime[i * p] = 1;
        if (i % p == 0) {
          break;
        }
      }
    }
    return pri.size();
  }
};

signed main() {
  Solution sol = Solution();
  cout << sol.countPrimes(2) << endl;

  return 0;
}