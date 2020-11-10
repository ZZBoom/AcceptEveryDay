#include <assert.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// ans = std::max(dp[left], dp[right], dp[left] + dp[right] + node_val);
// dp[node] = std::max(std::max(dp[left], dp[right]) + node_val, node_val);
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int ans;
  int dfs(TreeNode *now) {
    if (now == NULL) {
      return 0;
    }
    int ret = now->val;
    int left_val = dfs(now->left);
    int right_val = dfs(now->right);
    ret = std::max(ret, std::max(left_val, right_val) + now->val);

    ans = std::max(
        ans, std::max(left_val, std::max(right_val, left_val + right_val)) +
                 now->val);

    return ret;
  }
  int maxPathSum(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    ans = root->val;
    dfs(root);
    return ans;
  }
};
