#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
    int n = plants.size();
    int left = 0, right = n - 1;
    int a = capacityA, b = capacityB, ans = 0;
    while (left < right) {
      if (a >= plants[left]) {
        a -= plants[left];
      } else {
        a = capacityA - plants[left];
        ++ans;
      }
      if (b >= plants[right]) {
        b -= plants[right];
      } else {
        b = capacityB - plants[right];
        ++ans;
      }
      ++left;
      --right;
    }
    if (left == right) {
      if (a < plants[left] && b < plants[left]) {
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> plants = {2, 2, 3, 3};
  int capacityA = 3, capacityB = 4;
  Solution sol;
  cout << sol.minimumRefill(plants, capacityA, capacityB) << endl;

  return 0;
}