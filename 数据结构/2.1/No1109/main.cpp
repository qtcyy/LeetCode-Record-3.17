#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> arr(n + 2, 0);
    for (auto &book : bookings) {
      arr[book[0]] += book[2];
      arr[book[1] + 1] -= book[2];
    }
    for (int i = 0; i < n; i++) {
      arr[i + 1] += arr[i];
    }
    return vector<int>(arr.begin() + 1, arr.begin() + n + 1);
  }
};

signed main() {
  vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
  int n = 5;
  Solution sol = Solution();
  vector<int> ans = sol.corpFlightBookings(bookings, n);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}