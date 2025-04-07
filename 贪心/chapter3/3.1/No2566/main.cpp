#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minMaxDifference(int num) {
    vector<int> a;
    while (num) {
      a.push_back(num % 10);
      num /= 10;
    }
    reverse(a.begin(), a.end());
    // max
    vector<int> tmp(a);
    int n = a.size();
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (tmp[i] != 9) {
        tmp[i] = 9;
        flag = true;
        break;
      }
    }
    if (!flag) {
      tmp.back() = tmp.back() - 1;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
      max = max * 10 + tmp[i];
    }
    return max;
  }
};

signed main() {
  Solution sol;
  cout << sol.minMaxDifference(11891) << endl;

  return 0;
}