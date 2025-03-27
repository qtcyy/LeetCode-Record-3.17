#include <iostream>
#include <vector>
using namespace std;

// 二分做法
class Solution {
public:
  int findLatestStep(vector<int> &arr, int m) {
    int n = arr.size();
    auto check = [&](const int &mid) {
      vector<bool> list(n, 0);
      for (int i = 0; i < mid; i++) {
        list[arr[i]] = 1;
      }
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (list[i]) {
          ++count;
        } else {
          if (count == m) {
            return true;
          }
          count = 0;
        }
      }

      return false;
    };

    int l = -1, r = n + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l == -1 ? -1 : l + 1;
  }
};

class Solution2 {
public:
  int findLatestStep(vector<int> &arr, int m) {}
};

signed main() {
  vector<int> arr = {3, 5, 1, 2, 4};
  int m = 1;
  Solution sol;
  cout << sol.findLatestStep(arr, m) << endl;

  return 0;
}