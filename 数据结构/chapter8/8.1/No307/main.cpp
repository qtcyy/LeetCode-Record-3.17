#include <vector>
using namespace std;

class NumArray {
private:
  vector<int> tree;
  vector<int> &arr;

  inline int lowbit(int &x) { return x & -x; }

  void add(int i, int val) {
    while (i < tree.size()) {
      tree[i] += val;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int res = 0;
    while (i) {
      res += tree[i];
      i -= lowbit(i);
    }
    return res;
  }

public:
  NumArray(vector<int> &nums) : tree(nums.size() + 1), arr(nums) {
    for (int i = 0; i < arr.size(); i++) {
      add(i + 1, arr[i]);
    }
  }

  void update(int index, int val) {
    add(index + 1, val - arr[index]);
    arr[index] = val;
  }

  int sumRange(int left, int right) { return query(right + 1) - query(left); }
};