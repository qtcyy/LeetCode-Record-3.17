#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int n = fruits.size();
    unordered_map<int, int> cnt;
    int ans = 0, left = 0;
    for (int i = 0; i < n; i++) {
      ++cnt[fruits[i]];
      while (cnt.size() > 2) {
        if (!--cnt[fruits[left]]) {
          cnt.erase(fruits[left]);
        }
        ++left;
      }
      ans = max(ans, i - left + 1);
    }

    return ans;
  }
};

signed main() {
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  Solution sol;
  cout << sol.totalFruit(fruits) << endl;

  return 0;
}