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
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    int pos = 0;
    bool flag = false;
    vector<int> ans;
    function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
      if (!cur || flag) {
        return;
      }
      if (cur->val != voyage[pos++]) {
        flag = true;
        return;
      }
      if (cur->left && cur->right && cur->left->val != voyage[pos]) {
        ans.push_back(cur->val);
        dfs(cur->right);
        dfs(cur->left);
      } else {
        dfs(cur->left);
        dfs(cur->right);
      }
    };
    dfs(root);
    if (flag) {
      return {-1};
    }
    return ans;
  }
};

signed main() {
  vector<int> node = {1, 2, 3}, voyage = {1, 3, 2};
  TreeNode *root = buildTree(node);
  Solution sol;
  auto ans = sol.flipMatchVoyage(root, voyage);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}