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

const int mod = 1e9 + 7;

class Solution {
public:
  int maxProduct(TreeNode *root) {
    vector<int> rec;
    function<int(TreeNode *)> getsum = [&](TreeNode *node) -> int {
      if (!node) {
        return 0;
      }
      int val = getsum(node->left) + getsum(node->right) + node->val;
      rec.push_back(val);
      return val;
    };
    int sum = getsum(root);
    long long ans = 0;
    for (int &x : rec) {
      ans = max(ans, 1ll * x * (sum - x));
    }
    return ans % mod;
  }
};

signed main() {
  vector<int> node = {1, 2, 3, 4, 5, 6};
  TreeNode *root = buildTree(node);
  Solution sol;
  cout << sol.maxProduct(root) << endl;

  return 0;
}