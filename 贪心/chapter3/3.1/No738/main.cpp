#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    // 98765 -> 56789
    // 2333332->2333329
    vector<int> a;
    while (n) {
      a.push_back(n % 10);
      n /= 10;
    }
    reverse(a.begin(), a.end());
    int i0 = a.size() - 1;
    for (int i = 0; i + 1 < (int)a.size(); i++) {
      if (a[i] > a[i + 1]) {
        --a[i];
        i0 = i;
        break;
      }
    }
    // cout << i0 << endl;
    for (int i = i0 + 1; i < (int)a.size(); i++) {
      a[i] = 9;
    }
    int i = i0 - 1;
    while (i >= 0) {
      if (a[i] > a[i + 1]) {
        --a[i];
        a[i + 1] = 9;
      }
      --i;
    }
    int res = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      res = res * 10 + a[i];
    }
    return res;
  }
};

signed main() {
  Solution sol;
  cout << sol.monotoneIncreasingDigits(332) << endl;

  return 0;
}