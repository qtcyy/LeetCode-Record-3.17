#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend) {
    int n = times.size();
    vector<pair<int, int>> arrival;
    vector<pair<int, int>> leaving;
    for (int i = 0; i < n; i++) {
      arrival.emplace_back(times[i][0], i);
      leaving.emplace_back(times[i][1], i);
    }
    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
      pq.push(i);
    }
    unordered_map<int, int> seats;
    int j = 0;
    for (auto &&[time, person] : arrival) {
      while (j < n && leaving[j].first <= time) {
        pq.push(seats[leaving[j].second]);
        ++j;
      }
      int seat = pq.top();
      seats[person] = seat;
      pq.pop();
      if (person == targetFriend) {
        return seat;
      }
    }
    return -1;
  }
};

signed main() {
  vector<vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};
  int targetFriend = 1;
  Solution sol = Solution();
  cout << sol.smallestChair(times, targetFriend) << endl;

  return 0;
}