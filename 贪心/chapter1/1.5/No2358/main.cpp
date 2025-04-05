#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumGroups(vector<int> &grades) {
    ranges::sort(grades);
    int n = grades.size();
    if (n == 1)
      return 1;

    long long preSum = grades[0];
    long long sum = 0;
    int ans = 1;
    int pos = 0;
    int len = 1;

    for (int i = 1; i < n; i++) {
      sum += grades[i];

      if (sum > preSum && (i - pos) > len) {
        preSum = sum;
        sum = 0;
        len = i - pos;
        pos = i;
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> grades = {10, 6, 12, 7, 3, 5};
  Solution sol;
  cout << sol.maximumGroups(grades) << endl;

  return 0;
}