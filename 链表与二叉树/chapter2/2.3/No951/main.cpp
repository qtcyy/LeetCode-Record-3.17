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
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    function<bool(TreeNode *, TreeNode *)> dfs = [&](TreeNode *node1,
                                                     TreeNode *node2) -> bool {
      if (!node1 && !node2) {
        return true;
      } else if (!node1 || !node2) {
        return false;
      }
      if (node1->val != node2->val) {
        return false;
      }
      return dfs(node1->left, node2->left) && dfs(node1->right, node2->right) ||
             dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
    };
    return dfs(root1, root2);
  }
};

signed main() {
  vector<int> node1 = {1, 2, 3, 4, 5, 6, -1, -1, -1, 7, 8},
              node2 = {1, 3, 2, -1, 6, 4, 5, -1, -1, -1, -1, 8, 7};
  TreeNode *root1 = buildTree(node1), *root2 = buildTree(node2);
  Solution sol;
  cout << (sol.flipEquiv(root1, root2) ? "true" : "false") << endl;

  return 0;
}