#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumDeletions(string word, int k) {
    // 统计每个字符的频率
    vector<int> freq(26, 0);
    for (char c : word) {
      freq[c - 'a']++;
    }

    // 移除频率为0的字符，并排序
    vector<int> nonZeroFreq;
    for (int f : freq) {
      if (f > 0) {
        nonZeroFreq.push_back(f);
      }
    }
    sort(nonZeroFreq.begin(), nonZeroFreq.end());

    int n = word.length();
    int maxKeep = 0; // 最多能保留的字符数

    // 枚举每个频率作为下限
    for (int i = 0; i < nonZeroFreq.size(); i++) {
      int lower = nonZeroFreq[i]; // 下限
      int upper = lower + k;      // 上限

      int keep = 0; // 当前下限下能保留的字符数

      for (int j = 0; j < nonZeroFreq.size(); j++) {
        if (nonZeroFreq[j] < lower) {
          // 频率小于下限的字符不保留
          continue;
        } else if (nonZeroFreq[j] > upper) {
          // 频率大于上限的字符部分保留
          keep += upper;
        } else {
          // 频率在区间内的字符全部保留
          keep += nonZeroFreq[j];
        }
      }

      maxKeep = max(maxKeep, keep);
    }

    // 总长度减去最多能保留的字符数，就是需要删除的最小字符数
    return n - maxKeep;
  }
};

signed main() {
  string word = "dabdcbdcdcd";
  int k = 2;
  Solution sol;
  cout << "使用逆向思维的解法：" << sol.minimumDeletions(word, k) << endl;

  return 0;
}