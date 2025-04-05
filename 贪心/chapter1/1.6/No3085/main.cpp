#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumDeletions(string word, int k) {
    int cnt[26]{}, n = word.length();
    for (auto &ch : word) {
      ++cnt[ch - 'a'];
    }
    ranges::sort(cnt);
    vector<int> arr;
    for (int i = 0; i < 26; i++) {
      if (cnt[i]) {
        arr.push_back(cnt[i]);
      }
    }
    int ans = n, m = arr.size();
    for (int i = 0; i < m; i++) {
      // 区间偏移t
      for (int t = 0; t <= k; t++) {
        int down = max(0, arr[i] - k + t), up = arr[i] + t;
        // 比down小的删掉 比up大的减小到up
        int sum = 0;
        for (int j = 0; j < i; j++) {
          if (arr[j] >= down)
            break;
          sum += arr[j];
        }
        for (int j = m - 1; j > i; j--) {
          if (arr[j] <= up)
            break;
          sum += arr[j] - up;
        }
        ans = min(ans, sum);
      }
    }
    return ans;
  }
};

signed main() {
  string word = "dabdcbdcdcd";
  int k = 2;
  Solution sol;
  cout << sol.minimumDeletions(word, k) << endl;

  return 0;
}