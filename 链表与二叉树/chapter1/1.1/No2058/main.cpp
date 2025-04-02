#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *construct(const vector<int> &arr) {
  ListNode dummy(0);
  ListNode *cur = &dummy;
  for (auto &x : arr) {
    cur->next = new ListNode(x);
    cur = cur->next;
  }
  return dummy.next;
}

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    ListNode *cur = head->next, *pre = head;
    int maxn = 0, minn = INT_MAX;
    int prev = -1, i = 0, cnt = 0;
    int first = -1;
    while (cur->next) {
      if (cur->val > pre->val && cur->val > cur->next->val ||
          cur->val < pre->val && cur->val < pre->next->val) {
        ++cnt;
        if (first == -1) {
          first = i;
        } else {
          maxn = max(maxn, i - first);
        }
        if (prev != -1) {
          minn = min(minn, i - prev);
          prev = i;
        } else {
          prev = i;
        }
      }
      cur = cur->next;
      ++i;
    }
    if (cnt <= 2) {
      return {-1, -1};
    } else {
      return {minn, maxn};
    }
  }
};

signed main() {
  vector<int> head = {5, 3, 1, 2, 5, 1, 2};
  ListNode *node = construct(head);
  Solution sol;
  auto ans = sol.nodesBetweenCriticalPoints(node);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}