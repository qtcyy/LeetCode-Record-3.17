#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_set<int> arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

public:
  int countPrimeSetBits(int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; ++i) {
      int val = i, sum = 0;
      while (val) {
        sum += val & 1;
        val >>= 1;
      }
      ans += arr.contains(sum);
    }
    return ans;
  }
};

signed main() {
  int left = 6, right = 10;
  Solution sol = Solution();
  cout << sol.countPrimeSetBits(left, right) << endl;

  return 0;
}