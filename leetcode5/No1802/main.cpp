#include <iostream>
using namespace std;

class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    int left = 1, right = maxSum + 1;
    while (left + 1 < right) {
      int mid = (left + right) >> 1;
      if (check(mid, n, index, maxSum)) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return left;
  }

  inline bool check(int &mid, int &n, int &index, int &maxSum) {
    int left = index;
    int right = n - index - 1;
    return mid + cal(mid, left) + cal(mid, right) <= maxSum;
  }

  long long cal(int big, int len) {
    if (len + 1 < big) {
      int small = big - len;
      return (long)(big - 1 + small) * len / 2;
    } else {
      int ones = len - (big - 1);
      return (long)big * (big - 1) / 2 + ones;
    }
  }
};

signed main() {
  int n = 4, index = 2, maxSum = 6;
  Solution sol = Solution();
  cout << sol.maxValue(n, index, maxSum) << endl;

  return 0;
}