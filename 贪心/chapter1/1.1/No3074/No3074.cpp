#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    ranges::sort(capacity, greater<>());
    int sum = reduce(apple.begin(), apple.end());
    int cnt = 0;
    for (int i = 0; i < capacity.size(); i++) {
      cnt += capacity[i];
      if (cnt >= sum) {
        return i + 1;
      }
    }
    return -1;
  }
};

signed main() {
  vector<int> apple = {1, 3, 2}, capacity = {4, 3, 1, 5, 2};
  Solution sol;
  auto ans = sol.minimumBoxes(apple, capacity);
  cout << ans << endl;

  return 0;
}