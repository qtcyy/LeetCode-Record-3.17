#include <iostream>
using namespace std;

class Solution {
private:
  int process(int k) {
    long long l = 0, r = 5ll * k;

    auto check = [&](long long mid) -> bool {
      int sum = 0;
      while (mid) {
        sum += mid / 5;
        mid /= 5;
      }
      return sum < k;
    };
    while (l + 1 < r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  };

public:
  int preimageSizeFZF(int k) { return process(k + 1) - process(k); }
};

signed main() {
  Solution sol;
  cout << sol.preimageSizeFZF(3) << endl;

  return 0;
}