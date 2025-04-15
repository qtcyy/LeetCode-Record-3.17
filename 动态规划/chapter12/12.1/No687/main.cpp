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
  int longestUnivaluePath(TreeNode *root) {
    if (!root)
      return 0;
    int ans = 0;
    function<int(TreeNode *, int)> dfs = [&](TreeNode *node, int val) -> int {
      if (!node) {
        return 0;
      }
      int left = dfs(node->left, node->val);
      int right = dfs(node->right, node->val);
      ans = max(ans, left + right + 1);
      if (node->val == val)
        return max(left, right) + 1;
      return 0;
    };
    dfs(root, root->val);
    return ans - 1;
  }
};

signed main() {
  vector<int> node = {1, 4, 5, 4, 4, 5};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.longestUnivaluePath(root) << endl;

  return 0;
}