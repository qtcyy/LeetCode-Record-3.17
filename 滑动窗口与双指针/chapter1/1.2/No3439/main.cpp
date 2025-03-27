#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                  vector<int> &endTime) {
    int n = startTime.size();
    vector<int> arr;
    arr.push_back(startTime[0]);
    for (int i = 1; i < n; i++) {
      arr.push_back(startTime[i] - endTime[i - 1]);
    }
    arr.push_back(eventTime - endTime.back());
    int m = arr.size();
    vector<int> pre(m + 1, 0);
    for (int i = 0; i < m; i++) {
      pre[i + 1] = pre[i] + arr[i];
    }
    int ans = 0;
    ++k;
    for (int i = k - 1; i < m; i++) {
      ans = max(ans, pre[i + 1] - pre[i - k + 1]);
    }

    return ans;
  }
};

signed main() {
  int eventTime = 10, k = 1;
  vector<int> startTime = {0, 2, 9}, endTime = {1, 4, 10};
  Solution sol;
  cout << sol.maxFreeTime(eventTime, k, startTime, endTime) << endl;

  return 0;
}