#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();
    int left = 0, right = n - 1;
    while (left < right) {
      int val = numbers[left] + numbers[right];
      if (val == target) {
        return {left + 1, right + 1};
      } else if (val < target) {
        ++left;
      } else {
        --right;
      }
    }
    return {-1, -1};
  }
};

signed main() {
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  Solution sol;
  vector<int> ans = sol.twoSum(numbers, target);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}