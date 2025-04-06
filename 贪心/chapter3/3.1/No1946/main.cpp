#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string maximumNumber(string num, vector<int> &change) {
    // bool vis[10]{};

    int n = num.size();
    int start = -1;
    for (int i = 0; i < n; i++) {
      int val = num[i] - '0';
      if (change[val] > val) {
        start = i;
        break;
      }
    }
    for (int i = start; i < n; i++) {
      int val = num[i] - '0';
      if (change[val] >= val) {
        num[i] = change[num[i] - '0'] + '0';
      } else {
        break;
      }
    }
    return num;
  }
};

signed main() {
  string num = "132";
  vector<int> change = {9, 8, 5, 0, 3, 6, 4, 2, 6, 8};
  Solution sol;
  cout << sol.maximumNumber(num, change) << endl;

  return 0;
}