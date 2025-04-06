#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minimumBuckets(string hamsters) {
    int ans = 0, n = hamsters.size();
    for (int i = 1; i < n; i++) {
      if (hamsters[i] == '.' && hamsters[i - 1] == 'H') {
        ++ans;
        hamsters[i - 1] = 'Z';
        if (i < n - 1 && hamsters[i + 1] == 'H') {
          hamsters[i + 1] = 'Z';
        }
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (hamsters[i] == '.' && hamsters[i + 1] == 'H') {
        ++ans;
        hamsters[i + 1] = 'Z';
      }
    }
    cout << hamsters << endl;
    for (char &ch : hamsters) {
      if (ch == 'H') {
        return -1;
      }
    }
    return ans;
  }
};

signed main() {
  string street = ".HH.H.H.H..";
  Solution sol;
  cout << sol.minimumBuckets(street) << endl;
  return 0;
}