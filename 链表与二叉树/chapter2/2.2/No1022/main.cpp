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
  int sumRootToLeaf(TreeNode *root) {
    int ans = 0;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *cur, int val) {
      if (!cur) {
        return;
      }
      val <<= 1;
      val |= cur->val;
      if (!cur->left && !cur->right) {
        ans += val;
      }
      dfs(cur->left, val);
      dfs(cur->right, val);
    };
    dfs(root, 0);
    return ans;
  }
};

signed main() {
  vector<int> node = {1, 0, 1, 0, 1, 0, 1};
  Solution sol;
  TreeNode *root = buildTree(node);
  cout << sol.sumRootToLeaf(root) << endl;

  return 0;
}