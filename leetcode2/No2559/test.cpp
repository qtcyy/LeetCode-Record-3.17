#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

signed main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  partial_sum(arr.begin(), arr.end(), arr.begin());
  for (auto &num : arr) {
    cout << num << ' ';
  }

  return 0;
}