#include <functional>
#include <iostream>
#include <queue>
#include <utility>
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
  int rob(TreeNode *root) {
    function<pair<int, int>(TreeNode *)> dfs =
        [&](TreeNode *node) -> pair<int, int> {
      if (!node) {
        return {0, 0};
      }
      auto [l_rob, l_not_rob] = dfs(node->left);
      auto [r_rob, r_not_rob] = dfs(node->right);
      int rob = l_not_rob + r_not_rob + node->val;
      int not_rob = max(l_rob, l_not_rob) + max(r_rob, r_not_rob);
      return {rob, not_rob};
    };
    auto [x, y] = dfs(root);
    return max(x, y);
  }
};

signed main() {
  vector<int> node = {3, 2, 3, -1, 3, -1, 1};
  Solution sol;
  TreeNode *root = buildTree(node);
  cout << sol.rob(root) << endl;

  return 0;
}