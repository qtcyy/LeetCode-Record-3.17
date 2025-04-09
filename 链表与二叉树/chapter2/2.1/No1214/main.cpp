#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
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
  bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
    unordered_set<int> st;
    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
      if (!cur) {
        return;
      }
      st.insert(cur->val);
      dfs(cur->left);
      dfs(cur->right);
    };
    bool flag = false;
    function<void(TreeNode *)> dfs2 = [&](TreeNode *cur) {
      if (!cur) {
        return;
      }
      if (st.contains(target - cur->val)) {
        flag = true;
        return;
      }
      dfs2(cur->left);
      dfs2(cur->right);
    };
    dfs(root1);
    dfs2(root2);

    return flag;
  }
};

signed main() {
  vector<int> root1 = {2, 1, 4}, root2 = {1, 0, 3};
  int target = 5;
  TreeNode *tree1 = buildTree(root1), *tree2 = buildTree(root2);
  Solution sol;
  cout << (sol.twoSumBSTs(tree1, tree2, target) ? "true" : "false") << endl;

  return 0;
}