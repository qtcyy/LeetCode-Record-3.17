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
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> cnt;
    int mx = 0;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node) {
        return 0;
      }
      int sum = dfs(node->left) + dfs(node->right) + node->val;
      ++cnt[sum];
      mx = max(mx, cnt[sum]);
      return sum;
    };
    dfs(root);
    vector<int> ans;
    for (auto &&[val, c] : cnt) {
      if (c == mx) {
        ans.push_back(val);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> node = {5, 2, -3};
  Solution sol;
  TreeNode *root = buildTree(node);
  auto ans = sol.findFrequentTreeSum(root);
  for (int &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}