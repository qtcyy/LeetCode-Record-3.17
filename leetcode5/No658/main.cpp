#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    sort(arr.begin(), arr.end(), [x](const int &a, const int &b) {
      return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
    });
    sort(arr.begin(), arr.begin() + k);
    return vector<int>(arr.begin(), arr.begin() + k);
  }
};

signed main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 4, x = 3;
  Solution sol = Solution();
  vector<int> ans = sol.findClosestElements(arr, k, x);
  for (int &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}