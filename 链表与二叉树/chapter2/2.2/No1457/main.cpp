#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
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
  int pseudoPalindromicPaths(TreeNode *root) {
    int cnt[10]{};
    int ans = 0;
    auto check = [&]() {
      int sum = 0;
      for (int i = 0; i <= 9; i++) {
        if (cnt[i] & 1) {
          ++sum;
        }
      }
      cout << endl;
      if (sum <= 1) {
        ++ans;
      }
    };
    function<void(TreeNode * cur)> dfs = [&](TreeNode *cur) {
      if (!cur) {
        return;
      }
      ++cnt[cur->val];
      if (!cur->left && !cur->right) {
        check();
      }
      dfs(cur->left);
      dfs(cur->right);
      --cnt[cur->val];
    };
    dfs(root);
    return ans;
  }
};

signed main() {
  vector<int> node = {2, 3, 1, 3, 1, -1, 1};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.pseudoPalindromicPaths(root) << endl;

  return 0;
}