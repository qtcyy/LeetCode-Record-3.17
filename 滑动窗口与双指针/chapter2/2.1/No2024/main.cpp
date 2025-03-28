#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int n = answerKey.length();
    int left = 0, ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (answerKey[i] == 'F');
      while (cnt > k) {
        cnt -= (answerKey[left] == 'F');
        ++left;
      }
      ans = max(ans, i - left + 1);
    }
    left = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (answerKey[i] == 'T');
      while (cnt > k) {
        cnt -= (answerKey[left] == 'T');
        ++left;
      }
      ans = max(ans, i - left + 1);
    }
    return ans;
  }
};

signed main() {
  string answerKey = "TTFTTFTT";
  int k = 1;
  Solution sol;
  cout << sol.maxConsecutiveAnswers(answerKey, k) << endl;

  return 0;
}