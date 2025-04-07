#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &arr) {
    // 12765
    int mx = 0, pos = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (arr[i] > mx) {
        mx = arr[i];
        pos = i;
      }
    }
    int mx2 = 0, pos2 = n - 1;
    for (int i = pos + 1; i < n; i++) {
      if (arr[i] != mx && arr[i] > mx2) {
        mx2 = arr[i];
        pos2 = i;
      }
    }
    swap(arr[pos], arr[pos2]);
    return arr;
  }
};

class Solution2 {
public:
  vector<int> prevPermOpt1(vector<int> &arr) {
    // 12765
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > arr[i + 1]) {
        int j = n - 1;
        while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
          --j;
        }
        swap(arr[i], arr[j]);
        break;
      }
    }
    return arr;
  }
};

signed main() {
  vector<int> arr = {1, 9, 4, 6, 7};
  Solution2 sol;
  auto ans = sol.prevPermOpt1(arr);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}