#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> numSmallerByFrequency(vector<string> &queries,
                                    vector<string> &words) {
    auto f = [](string s) {
      char minn = 'z';
      for (char &ch : s) {
        minn = min(minn, ch);
      }
      int sum = 0;
      for (char &ch : s) {
        if (ch == minn) {
          ++sum;
        }
      }
      return sum;
    };
    vector<int> arr;
    for (auto &word : words) {
      arr.push_back(f(word));
    }
    sort(arr.begin(), arr.end());
    vector<int> res;
    for (auto &s : queries) {
      int val = f(s);
      int pos = arr.end() - upper_bound(arr.begin(), arr.end(), val);
      res.push_back(pos);
    }
    return res;
  }
};

signed main() {
  vector<string> queries = {"bbb", "cc"}, words = {"a", "aa", "aaa", "aaaa"};
  Solution sol = Solution();
  vector<int> ans = sol.numSmallerByFrequency(queries, words);
  for (auto &x : ans) {
    cout << x << ' ';
  }

  return 0;
}