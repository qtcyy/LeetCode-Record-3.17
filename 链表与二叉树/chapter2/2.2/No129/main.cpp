#include <algorithm>
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
  int sumNumbers(TreeNode *root) {
    int ans = 0;
    auto calc = [&](vector<int> s) {
      int val = 0;
      for (auto &x : s) {
        val = val * 10 + x;
      }
      ans += val;
    };
    function<void(TreeNode *, vector<int>)> dfs = [&](TreeNode *cur,
                                                      vector<int> s) {
      if (!cur) {
        return;
      }
      s.push_back(cur->val);
      if (!cur->left && !cur->right) {
        calc(s);
        return;
      }
      dfs(cur->left, s);
      dfs(cur->right, s);
    };
    dfs(root, {});

    return ans;
  }
};

signed main() {
  vector<int> node = {4, 9, 0, 5, 1};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.sumNumbers(root) << endl;

  return 0;
}