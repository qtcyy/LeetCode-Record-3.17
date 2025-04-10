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
  int countUnivalSubtrees(TreeNode *root) {
    int count = 0;
    function<bool(TreeNode *)> dfs = [&](TreeNode *node) -> bool {
      if (!node) {
        return true;
      }
      bool left = dfs(node->left);
      bool right = dfs(node->right);
      if (!left || !right) {
        return false;
      }
      if (node->left && node->left->val != node->val) {
        return false;
      }
      if (node->right && node->right->val != node->val) {
        return false;
      }
      ++count;
      return true;
    };
    dfs(root);
    return count;
  }
};

signed main() {
  vector<int> node = {5, 1, 5, 5, 5, -1, 5};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.countUnivalSubtrees(root) << endl;

  return 0;
}