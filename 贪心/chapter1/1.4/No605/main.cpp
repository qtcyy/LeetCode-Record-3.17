#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    int m = flowerbed.size();
    for (int i = 1; i + 1 < m; i++) {
      if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
        flowerbed[i] = 1;
        --n;
      }
    }
    return n <= 0;
  }
};

signed main() {
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  int n = 1;
  Solution sol;
  cout << sol.canPlaceFlowers(flowerbed, n) << endl;

  return 0;
}