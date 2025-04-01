#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;
  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  inline void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      f[x] = y;
    }
  }

public:
  bool gcdSort(vector<int> &nums) {
    int n = nums.size();
    int N = ranges::max(nums);
    vector<int> arr(nums);
    f.resize(N + 1);
    iota(f.begin(), f.end(), 0);
    for (auto &x : nums) {
      int xx = x;
      for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
          merge(xx, i);
          for (x /= i; x % i == 0; x /= i)
            ;
        }
      }
      if (x > 1) {
        merge(x, xx);
      }
      x = xx;
    }
    ranges::sort(arr);
    for (int i = 0; i < n; i++) {
      int x = find(arr[i]), y = find(nums[i]);
      if (x != y) {
        return false;
      }
    }
    return true;
  }
};

signed main() {
  vector<int> nums = {10, 5, 9, 3, 15};
  Solution sol;
  cout << (sol.gcdSort(nums) ? "true" : "false") << endl;

  return 0;
}