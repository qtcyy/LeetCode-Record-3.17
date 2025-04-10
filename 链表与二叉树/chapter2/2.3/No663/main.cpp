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
  bool checkEqualTree(TreeNode *root) {
    vector<int> rec;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
      if (!node)
        return 0;
      int val = dfs(node->left) + dfs(node->right) + node->val;
      rec.push_back(val);
      return val;
    };
    int sum = dfs(root);
    rec.pop_back();
    for (int &x : rec) {
      if (sum - x == x) {
        return true;
      }
    }
    return false;
  }
};

signed main() {
  vector<int> node = {5, 10, 10, -1, -1, 2, 3};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << (sol.checkEqualTree(root) ? "true" : "false") << endl;

  return 0;
}