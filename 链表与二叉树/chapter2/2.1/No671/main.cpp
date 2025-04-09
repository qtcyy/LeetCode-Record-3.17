#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 根据层序遍历数组构建二叉树，-1表示空节点
TreeNode *buildTree(vector<int> &nums) {
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  TreeNode *root = new TreeNode(nums[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < nums.size()) {
    TreeNode *curr = q.front();
    q.pop();

    // 处理左子节点
    if (i < nums.size()) {
      if (nums[i] != -1) {
        curr->left = new TreeNode(nums[i]);
        q.push(curr->left);
      }
      i++;
    }

    // 处理右子节点
    if (i < nums.size()) {
      if (nums[i] != -1) {
        curr->right = new TreeNode(nums[i]);
        q.push(curr->right);
      }
      i++;
    }
  }

  return root;
}

class Solution {
public:
  int findSecondMinimumValue(TreeNode *root) {
    vector<int> arr;
    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
      if (!cur) {
        return;
      }
      arr.push_back(cur->val);
      dfs(cur->left);
      dfs(cur->right);
    };
    dfs(root);
    int mn = ranges::min(arr);
    int ans = INT_MAX;
    for (auto &x : arr) {
      if (x == mn)
        continue;
      ans = min(ans, x);
    }
    return ans >= INT_MAX ? -1 : ans;
  }
};

signed main() {
  vector<int> node = {2, 2, 5, -1, -1, 5, 7};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.findSecondMinimumValue(root) << endl;

  return 0;
}