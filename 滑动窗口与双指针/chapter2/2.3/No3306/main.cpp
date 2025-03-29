#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  long long countOfSubstrings(string word, int k) {
    int n = word.size();
    auto slide = [&](const int &target) -> long long {
      int cnt[26]{};
      int left = 0;
      long long ans = 0;
      unordered_set<char> base = {'a', 'e', 'i', 'o', 'u'};
      auto check = [&]() -> bool {
        for (auto &un : base) {
          if (!cnt[un - 'a']) {
            return false;
          }
        }
        return true;
      };
      int sum = 0;
      for (int i = 0; i < n; i++) {
        ++cnt[word[i] - 'a'];
        if (!base.contains(word[i])) {
          ++sum;
        }
        while (check() && sum >= target) {
          if (!base.contains(word[left])) {
            --sum;
          }
          --cnt[word[left++] - 'a'];
        }
        ans += left;
      }
      return ans;
    };

    return slide(k) - slide(k + 1);
  }
};

signed main() {
  string word = "ieaouqqieaouqq";
  int k = 1;
  Solution sol;
  cout << sol.countOfSubstrings(word, k) << endl;

  return 0;
}