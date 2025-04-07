#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumSwap(int num) {
    vector<int> a;
    while (num) {
      a.push_back(num % 10);
      num /= 10;
    }
    reverse(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
      if (a[i] < a[i + 1]) {
        swap(a[i], a[i + 1]);
        break;
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = res * 10 + a[i];
    }
    return res;
  }
};

class Solution2 {
public:
  int maximumSwap(int num) {
    vector<int> a;
    while (num) {
      a.push_back(num % 10);
      num /= 10;
    }
    reverse(a.begin(), a.end());
    int n = a.size();
    vector<pair<int, int>> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > suf[i + 1].first) {
        suf[i] = make_pair(a[i], i);
      } else {
        suf[i] = suf[i - 1];
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] < suf[i + 1].first) {
        swap(a[i], a[suf[i + 1].second]);
        break;
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = res * 10 + a[i];
    }
    return res;
  }
};

signed main() {
  Solution2 sol;
  cout << sol.maximumSwap(2736) << endl;

  return 0;
}