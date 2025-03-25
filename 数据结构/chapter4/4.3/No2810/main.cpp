#include <deque>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string finalString(string s) {
    int signal = 0;
    deque<char> deq;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      char ch = s[i];
      if (ch == 'i') {
        signal ^= 1;
      } else {
        if (signal) {
          deq.push_back(ch);
        } else {
          deq.push_front(ch);
        }
      }
    }
    if (signal) {
      return string(deq.begin(), deq.end());
    } else {
      return string(deq.rbegin(), deq.rend());
    }
  }
};

signed main() {
  string s = "string";
  Solution sol = Solution();
  cout << sol.finalString(s) << endl;

  return 0;
}