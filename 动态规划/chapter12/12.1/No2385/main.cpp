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
  int amountOfTime(TreeNode *root, int start) {
    int ans = 0;
    function<pair<int, bool>(TreeNode *)> dfs =
        [&](TreeNode *node) -> pair<int, bool> {
      if (!node) {
        return {0, false};
      }
      auto [left, l_found] = dfs(node->left);
      auto [right, r_found] = dfs(node->right);
      if (node->val == start) {
        ans = max(left, right);
        return {1, true};
      }
      if (l_found || r_found) {
        ans = max(ans, left + right);
        return {(l_found ? left : right) + 1, true};
      }
      return {max(left, right) + 1, false};
    };
    dfs(root);
    return ans;
  }
};

signed main() {
  vector<int> node = {1, 5, 3, -1, 4, 10, 6, 9, 2};
  int start = 3;
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.amountOfTime(root, start) << endl;

  return 0;
}