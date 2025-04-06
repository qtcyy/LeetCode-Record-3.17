#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximum69Number(int num) {
    vector<int> arr;
    while (num) {
      arr.push_back(num % 10);
      num /= 10;
    }
    reverse(arr.begin(), arr.end());
    for (auto &x : arr) {
      if (x == 6) {
        x = 9;
        break;
      }
    }
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = ans * 10 + arr[i];
    }
    return ans;
  }
};

signed main() {
  int num = 9669;
  Solution sol;
  cout << sol.maximum69Number(num) << endl;

  return 0;
}