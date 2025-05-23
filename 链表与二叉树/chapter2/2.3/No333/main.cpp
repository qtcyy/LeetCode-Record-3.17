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
  int largestBSTSubtree(TreeNode *root) {
    int mx = 0, count = 0;
    function<bool(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node) {
        return true;
      }
      int cur = count++;
      bool left = dfs(node->left), right = dfs(node->right);
      bool check = left && right;
      if (!check)
        return false;
      if (node->left && node->left->val >= node->val)
        return false;
      if (node->right && node->right->val <= node->val)
        return false;
      mx = max(mx, count - cur);
      return true;
    };
    dfs(root);

    return mx;
  }
};

signed main() {
  vector<int> node = {10, 5, 15, 1, 8, -1, 7};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.largestBSTSubtree(root) << endl;

  return 0;
}